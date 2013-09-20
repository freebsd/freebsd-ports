# Created by: Brent J. Nordquist <bjn@visi.com>
# $FreeBSD$

PORTNAME=	cgiwrap
PORTVERSION=	4.1
CATEGORIES=	www security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Securely execute Web CGI scripts

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	CGI_OWNER CGI_GROUP CGI_SETUID CGI_SETGID \
		CGI_GROUP_WRITABLE CGI_WORLD_WRITABLE DEBUG \
		DOCS NPH USE_REDIRECT_URL USE_SCRIPT_URL
OPTIONS_DEFAULT=CGI_OWNER CGI_GROUP CGI_SETUID CGI_SETGID \
		CGI_GROUP_WRITABLE CGI_WORLD_WRITABLE

CGI_OWNER_DESC=	Check CGI file owner
CGI_GROUP_DESC=	Check CGI file group
CGI_SETUID_DESC=Check CGI file setuid permissions
CGI_SETGID_DESC=Check CGI file setgid permissions
CGI_GROUP_WRITABLE_DESC=Check CGI g+w file permissions
CGI_WORLD_WRITABLE_DESC=Check CGI o+w file permissions
USE_REDIRECT_URL_DESC=Use REDIRECT_URL to build SCRIPT_NAME
USE_SCRIPT_URL_DESC=Use SCRIPT_URL to build SCRIPT_NAME
NPH_DESC=	Enable nph binaries
DEBUG_DESC=	Enable cgiwrapd binaries

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

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httpd-user=${WWWOWN} \
		--with-install-group=${WWWGRP} \
		--with-install-dir=${INSTALL_DIR} \
		--with-cgi-dir=${USER_CGIDIR} \
		--with-allow-file=${ALLOW_FILE} \
		--with-deny-file=${DENY_FILE} \
		--with-check-shell \
		--with-wall

NO_STAGE=	yes
.include <bsd.port.options.mk>

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
.if empty(PORT_OPTIONS:MCGI_OWNER)
CONFIGURE_ARGS+=	--without-check-owner
.endif
.if empty(PORT_OPTIONS:MCGI_GROUP)
CONFIGURE_ARGS+=	--without-check-group
.endif
.if empty(PORT_OPTIONS:MCGI_SETUID)
CONFIGURE_ARGS+=	--without-check-setuid
.endif
.if empty(PORT_OPTIONS:MCGI_SETGID)
CONFIGURE_ARGS+=	--without-check-setgid
.endif
.if empty(PORT_OPTIONS:MCGI_GROUP_WRITABLE)
CONFIGURE_ARGS+=	--without-check-group-writable
.endif
.if empty(PORT_OPTIONS:MCGI_WORLD_WRITABLE)
CONFIGURE_ARGS+=	--without-check-world-writable
.endif
.if ${PORT_OPTIONS:MUSE_REDIRECT_URL}
CONFIGURE_ARGS+=	--with-use-redirect-url
.endif
.if ${PORT_OPTIONS:MUSE_SCRIPT_URL}
CONFIGURE_ARGS+=	--with-use-script-url
.endif

.if empty(PORT_OPTIONS:MNPH)
PLIST_SUB+=		NPHFLAG="@comment "
CONFIGURE_ARGS+=	--without-nph
.else
PLIST_SUB+=		NPHFLAG=
.endif

.if ${PORT_OPTIONS:MDEBUG}
PLIST_SUB+=		DEBUGFLAG=
CONFIGURE_ARGS+=	--with-cgiwrapd
.else
PLIST_SUB+=		DEBUGFLAG="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
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
.if ${PORT_OPTIONS:MDEBUG}
	@${STRIP_CMD} ${INSTALL_DIR}/cgiwrapd
	@${CHMOD} 4550 ${INSTALL_DIR}/cgiwrapd
.if ${PORT_OPTIONS:MNPH}
	@${STRIP_CMD} ${INSTALL_DIR}/nph-cgiwrapd
	@${CHMOD} 4550 ${INSTALL_DIR}/nph-cgiwrapd
.endif
.endif
.if ${PORT_OPTIONS:MDOCS}
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

.include <bsd.port.mk>
