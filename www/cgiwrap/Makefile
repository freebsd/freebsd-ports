# New ports collection makefile for:    cgiwrap
# Date created:         30 July 1998
# Whom:                 Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	cgiwrap
PORTVERSION=	3.9
PORTREVISION=	2
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@jdc.parodius.com
COMMENT=	Securely execute ~user CGI scripts

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httpd-user=${WWWOWN} \
		--with-install-group=${WWWGRP} \
		--with-install-dir=${WITH_MAIN_CGIDIR} \
		--with-cgi-dir=${WITH_USER_CGIDIR} \
		--with-local-contact=${WITH_EMAIL} \
		--with-allow-file=${WITH_ALLOWFILE} \
		--with-deny-file=${WITH_DENYFILE}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

## Available knobs:
##
##   WITH_MAIN_CGIDIR:     location of the cgiwrap binaries
#
# This is the directory where the cgiwrap binaries (i.e. the setuid
# root binaries) get installed to.
#
WITH_MAIN_CGIDIR?=	${PREFIX}/www/cgi-bin

##   WITH_USER_CGIDIR:     location of the CGI directory per user
##                         account (i.e. public_html/cgi-bin)
#
# Set this to the directory (relative to each user's home) where CGI
# scripts will be found.  Common alternate values are "www/cgi-bin"
# (a.k.a. ~user/www/cgi-bin) and "cgi-bin" (a.k.a. ~user/cgi-bin)
#
WITH_USER_CGIDIR?=	public_html/cgi-bin

##   WITH_ALLOWFILE:       location/name of the cgiwrap.allow ACL file
##   WITH_DENYFILE:        location/name of the cgiwrap.deny ACL file
#
WITH_ALLOWFILE?=	${PREFIX}/etc/${PORTNAME}.allow
WITH_DENYFILE?=		${PREFIX}/etc/${PORTNAME}.deny

##   WITH_EMAIL:           cgiwrap administrator's Email address
#
WITH_EMAIL?=		webmaster@dummy-host.example.com

##   WITH_LOGGING:         enables cgiwrap logging; specifies the
##                         path and filename of the logfile
#
.if defined(WITH_LOGGING)
CONFIGURE_ARGS+=	--with-logging-file=${WITH_LOGGING}
.endif

##   WITH_DEBUG:           enables cgiwrap debugging support, via
##                         the 'cgiwrapd' binary
#
.if defined(WITH_DEBUG)
PLIST_SUB+=	CGIWRAPDFLAG=
.else
PLIST_SUB+=	CGIWRAPDFLAG="@comment "
.endif

##   WITHOUT_CHECK_OWNER:  disable CGI file ownership checks
##   WITHOUT_CHECK_GROUP:  disable CGI file group checks
##   WITHOUT_CHECK_SETUID: disable CGI file setuid permissions check
##   WITHOUT_CHECK_SETGID: disable CGI file setgid permissions check
##   WITHOUT_CHECK_GROUP_WRITABLE:
##          disable CGI file group-writable permissions check
##   WITHOUT_CHECK_WORLD_WRITABLE:
##          disable CGI file world-writable permissions check
#
.if defined(WITHOUT_CHECK_OWNER)
CONFIGURE_ARGS+=	--without-check-owner
.endif
.if defined(WITHOUT_CHECK_GROUP)
CONFIGURE_ARGS+=	--without-check-group
.endif
.if defined(WITHOUT_CHECK_SETUID)
CONFIGURE_ARGS+=	--without-check-setuid
.endif
.if defined(WITHOUT_CHECK_SETGID)
CONFIGURE_ARGS+=	--without-check-setgid
.endif
.if defined(WITHOUT_CHECK_GROUP_WRITABLE)
CONFIGURE_ARGS+=	--without-check-group-writable
.endif
.if defined(WITHOUT_CHECK_WORLD_WRITABLE)
CONFIGURE_ARGS+=	--without-check-world-writable
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	accesscontrol.html afs.html changes.html \
		chroot.html comments.html download.html faq.html \
		index.html install.html intro.html maillist.html \
		notes.html pubs.html quickref.html setup.html \
		thanks.html todo.html tricks.html y2k.html
.endif

show-options:
	@${SED} -ne 's/^##//p' ${.CURDIR}/Makefile

pre-install:
	@${MKDIR} ${WITH_MAIN_CGIDIR}

post-install:
	@${STRIP_CMD} ${WITH_MAIN_CGIDIR}/cgiwrap
	@${CHMOD} 4550 ${WITH_MAIN_CGIDIR}/cgiwrap
.if !defined(WITH_DEBUG)
	@${RM} ${WITH_MAIN_CGIDIR}/cgiwrapd
	@${RM} ${WITH_MAIN_CGIDIR}/nph-cgiwrapd
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/htdocs/${f} ${DOCSDIR}
.endfor
.endif
	@${SED}	-e's,%%MAIN_CGIDIR%%,${WITH_MAIN_CGIDIR},g' \
		-e's,%%ALLOWFILE%%,${WITH_ALLOWFILE},g' \
		-e's,%%DENYFILE%%,${WITH_DENYFILE},g' \
		${MASTERDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
