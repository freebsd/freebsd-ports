# Created by: Brent J. Nordquist <bjn@visi.com>
# $FreeBSD$

PORTNAME=	cgiwrap
PORTVERSION=	4.1
CATEGORIES=	www security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Securely execute Web CGI scripts

LICENSE=	GPLv2

OPTIONS_DEFINE=	CGI_OWNER CGI_GROUP CGI_SETUID CGI_SETGID \
		CGI_GROUP_WRITABLE CGI_WORLD_WRITABLE DEBUG \
		DOCS NPH USE_REDIRECT_URL USE_SCRIPT_URL
OPTIONS_DEFAULT=CGI_OWNER CGI_GROUP CGI_SETUID CGI_SETGID \
		CGI_GROUP_WRITABLE CGI_WORLD_WRITABLE
OPTIONS_SUB=	yes

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

SUB_FILES=	pkg-message
SUB_LIST+=	INSTALL_DIR=${INSTALL_DIR} \
		ALLOW_FILE=${ALLOW_FILE} \
		DENY_FILE=${DENY_FILE}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httpd-user=${WWWOWN} \
		--with-install-group=${WWWGRP} \
		--with-install-dir=${INSTALL_DIR} \
		--with-cgi-dir=${USER_CGIDIR} \
		--with-allow-file=${ALLOW_FILE} \
		--with-deny-file=${DENY_FILE} \
		--with-check-shell \
		--with-wall

CGI_OWNER_CONFIGURE_WITH=	check-owner
CGI_GROUP_CONFIGURE_WITH=	check-group
CGI_SETUID_CONFIGURE_WITH=	check-setuid
CGI_SETGID_CONFIGURE_WITH=	check-setgid
CGI_GROUP_WRITABLE_CONFIGURE_WITH=	check-group-writable
CGI_WORLD_WRITABLE_CONFIGURE_WITH=	check-world-writable
USE_REDIRECT_URL_CONFIGURE_WITH=	use-redirect-url
USE_SCRIPT_URL_CONFIGURE_WITH=	use-script-url
NPH_CONFIGURE_WITH=		nph
DEBUG_CONFIGURE_WITH=		cgiwrapd

PORTDOCS=	accesscontrol.html afs.html changes.html \
		chroot.html comments.html download.html faq.html \
		index.html install.html intro.html maillist.html \
		notes.html pubs.html quickref.html setup.html \
		thanks.html todo.html tricks.html y2k.html

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

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALL_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cgiwrap ${STAGEDIR}${INSTALL_DIR}
.for link in cgiwrapd nph-cgiwrap nph-cgiwrapd
	${LN} -sf cgiwrap ${STAGEDIR}${INSTALL_DIR}/${link}
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/htdocs && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
