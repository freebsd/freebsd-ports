# New ports collection makefile for:    cgiwrap
# Date created:         30 July 1998
# Whom:                 Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	cgiwrap
PORTVERSION=	3.9
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@jdc.parodius.com
COMMENT=	Securely execute ~user CGI scripts

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httpd-user=${WWWOWN} \
		--with-install-group=${WWWGRP} \
		--with-install-dir=${MAINCGIDIR} \
		--with-cgi-dir=${CGIWRAP_CGIDIR} \
		--with-local-contact=${CGIWRAP_CONTACT} \
		--with-allow-file=${CGIWRAP_ALLOWFILE} \
		--with-deny-file=${CGIWRAP_DENYFILE}

#
# Set this to the directory (relative to each user's home) where CGI
# scripts will be found.  Common alternate values are "www/cgi-bin"
# (a.k.a. ~user/www/cgi-bin) and "cgi-bin" (a.k.a. ~user/cgi-bin)
#
CGIWRAP_CGIDIR?=	public_html/cgi-bin

#
# MAINCGIDIR is the directory the cgiwrap binaries get installed to.
#
MAINCGIDIR?=	${PREFIX}/www/cgi-bin

#
# The allow and deny files control access to cgiwrap.
#
CGIWRAP_ALLOWFILE?=	${PREFIX}/etc/${PORTNAME}.allow
CGIWRAP_DENYFILE?=	${PREFIX}/etc/${PORTNAME}.deny

#
# Set the contact Email address.
#
CGIWRAP_CONTACT?=	webmaster@dummy-host.example.com

#
# Define CGIWRAP_LOGGING and specify where you want the logfile.
#
.if defined(CGIWRAP_LOGGING)
CONFIGURE_ARGS+=	--with-logging-file=${CGIWRAP_LOGGING}
.endif

#
# Some users enjoy being able to debug their own CGI scripts, since
# the standard "Internal server error" response doesn't help much.
# Administrators may find this useful as well.  See the cgiwrap
# documentation for details on how to use this.
#
.if defined(CGIWRAP_DEBUG)
PLIST_SUB+=	CGIWRAPDFLAG=
.else
PLIST_SUB+=	CGIWRAPDFLAG="@comment "
.endif

#
# A slew of --without-* configure flags exist for cgiwrap.  You
# should refer to the cgiwrap documentation for details regarding
# what these do, and when (if) they're necessary.
#
###
.if defined(CGIWRAP_WITHOUT_CHECK_OWNER)
CONFIGURE_ARGS+=	--without-check-owner
.endif
.if defined(CGIWRAP_WITHOUT_CHECK_GROUP)
CONFIGURE_ARGS+=	--without-check-group
.endif
.if defined(CGIWRAP_WITHOUT_CHECK_SETUID)
CONFIGURE_ARGS+=	--without-check-setuid
.endif
.if defined(CGIWRAP_WITHOUT_CHECK_SETGID)
CONFIGURE_ARGS+=	--without-check-setgid
.endif
.if defined(CGIWRAP_WITHOUT_CHECK_GROUP_WRITABLE)
CONFIGURE_ARGS+=	--without-check-group-writable
.endif
.if defined(CGIWRAP_WITHOUT_CHECK_WORLD_WRITABLE)
CONFIGURE_ARGS+=	--without-check-world-writable
.endif

pre-install:
	@${MKDIR} ${MAINCGIDIR}

post-install:
	@${STRIP_CMD} ${MAINCGIDIR}/cgiwrap
	@${CHMOD} 4550 ${MAINCGIDIR}/cgiwrap
.if !defined(CGIWRAP_WITH_DEBUG)
	@${RM} ${MAINCGIDIR}/cgiwrapd ${MAINCGIDIR}/nph-cgiwrapd
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in accesscontrol.html afs.html changes.html chroot.html	\
		comments.html download.html faq.html index.html		\
		install.html intro.html maillist.html notes.html	\
		pubs.html quickref.html setup.html thanks.html		\
		todo.html tricks.html y2k.html
	@${INSTALL_DATA} ${WRKSRC}/htdocs/${file} ${DOCSDIR}
.endfor
	@${ECHO} "Documentation installed in ${DOCSDIR}"
.endif
	@${CAT} ${PKGMESSAGE} | ${SED} -e's#%%PREFIX%%#${PREFIX}#g'

.include <bsd.port.mk>
