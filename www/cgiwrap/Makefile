# New ports collection makefile for:    cgiwrap
# Date created:         30 July 1998
# Whom:                 Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	cgiwrap
PORTVERSION=	3.9
PORTREVISION=	3
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@jdc.parodius.com
COMMENT=	Securely execute Web CGI scripts

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	CGI_OWNER "Check CGI file owner" on \
		CGI_GROUP "Check CGI file group" on \
		CGI_SETUID "Check CGI file setuid permissions" on \
		CGI_SETGID "Check CGI file setgid permissions" on \
		CGI_GROUP_WRITABLE "Check CGI g+w file permissions" on \
		CGI_WORLD_WRITABLE "Check CGI o+w file permissions" on \
		NPH "Enable nph binaries" off \
		DEBUG "Enable cgiwrapd binaries" off

##
# INSTALL_DIR
#
# Specify the location of the cgiwrap binaries.  This is the directory
# where the cgiwrap binaries get installed in.
#
INSTALL_DIR?=	${PREFIX}/www/cgi-bin

##
# USER_CGIDIR
#
# Specify the location of the CGI directory ~user accounts will store
# CGIs in.  This is "home directory relative".  Alternatives include
# "www/cgi-bin" and "cgi-bin".
#
USER_CGIDIR?=	public_html/cgi-bin

##
# ALLOW_FILE
# DENY_FILE
#
# Full path to the allow and deny files for CGI access.  These files
# contain the username of the UNIX account who will be allowed/denied
# using the cgiwrap binary.
#
ALLOW_FILE?=	${PREFIX}/etc/${PORTNAME}.allow
DENY_FILE?=	${PREFIX}/etc/${PORTNAME}.deny

##
# LOG_FILE
#
# Enables cgiwrap logging (when a user called cgiwrap, its arguments,
# and who ran it).  Specify the full path to the logfile.
#
.if defined(LOG_FILE)
CONFIGURE_ARGS+=	--with-logging-file=${LOG_FILE}
.else
CONFIGURE_ARGS+=	--without-logging-file
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httpd-user=${WWWOWN} \
		--with-install-group=${WWWGRP} \
		--with-install-dir=${INSTALL_DIR} \
		--with-cgi-dir=${USER_CGIDIR} \
		--with-allow-file=${ALLOW_FILE} \
		--with-deny-file=${DENY_FILE} \
		--with-wall

.include <bsd.port.pre.mk>

.if !defined(WITH_CGI_OWNER)
CONFIGURE_ARGS+=	--without-check-owner
.endif
.if !defined(WITH_CGI_GROUP)
CONFIGURE_ARGS+=	--without-check-group
.endif
.if !defined(WITH_CGI_SETUID)
CONFIGURE_ARGS+=	--without-check-setuid
.endif
.if !defined(WITH_CGI_SETGID)
CONFIGURE_ARGS+=	--without-check-setgid
.endif
.if !defined(WITH_CGI_GROUP_WRITABLE)
CONFIGURE_ARGS+=	--without-check-group-writable
.endif
.if !defined(WITH_CGI_WORLD_WRITABLE)
CONFIGURE_ARGS+=	--without-check-world-writable
.endif

.if !defined(WITH_NPH)
PLIST_SUB+=		NPHFLAG="@comment "
CONFIGURE_ARGS+=	--without-nph
.else
PLIST_SUB+=		NPHFLAG=
.endif

.if !defined(WITH_DEBUG)
PLIST_SUB+=		DEBUGFLAG="@comment "
CONFIGURE_ARGS+=	--without-cgiwrapd
.else
PLIST_SUB+=		DEBUGFLAG=
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	accesscontrol.html afs.html changes.html \
		chroot.html comments.html download.html faq.html \
		index.html install.html intro.html maillist.html \
		notes.html pubs.html quickref.html setup.html \
		thanks.html todo.html tricks.html y2k.html
.endif

pre-install:
	@${MKDIR} ${INSTALL_DIR}

post-install:
	@${STRIP_CMD} ${INSTALL_DIR}/cgiwrap
	@${CHMOD} 4550 ${INSTALL_DIR}/cgiwrap
.if defined(WITH_DEBUG)
	@${STRIP_CMD} ${INSTALL_DIR}/cgiwrapd
	@${CHMOD} 4550 ${INSTALL_DIR}/cgiwrapd
.if defined(WITH_NPH)
	@${STRIP_CMD} ${INSTALL_DIR}/nph-cgiwrapd
	@${CHMOD} 4550 ${INSTALL_DIR}/nph-cgiwrapd
.endif
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/htdocs/${f} ${DOCSDIR}
.endfor
.endif
	@${SED}	-e's,%%INSTALL_DIR%%,${INSTALL_DIR},g' \
		-e's,%%ALLOW_FILE%%,${ALLOW_FILE},g' \
		-e's,%%DENY_FILE%%,${DENY_FILE},g' \
		${MASTERDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
