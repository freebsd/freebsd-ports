# $FreeBSD$

PORTNAME=	fnord
PORTVERSION=	1.11
CATEGORIES=	www
MASTER_SITES=	http://www.fefe.de/fnord/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast webserver with CGI-capability

LICENSE=	GPLv2

USES=		gmake tar:bzip2

PLIST_FILES=	bin/fnord \
		bin/fnord-conf \
		bin/fnord.inetd

SUB_FILES=	pkg-message fnord.inetd

OPTIONS_DEFINE=	DAEMONTOOLS TCPSERVER CGI DIR_LIST SYSTEM_SYMLINK_DEREF OLD_STYLE_REDIRECT
OPTIONS_DEFAULT=	CGI DIR_LIST
DAEMONTOOLS_DESC=	Use DJB's daemontools
TCPSERVER_DESC=		Use DJB's tcpserver
CGI_DESC=		Enable CGI support
DIR_LIST_DESC=		Enable directory listing
SYSTEM_SYMLINK_DEREF_DESC=	Enable system symlink (needs DIR_LIST)
OLD_STYLE_REDIRECT_DESC= Enable old style redirection

DAEMONTOOLS_RUN_DEPENDS=	setuidgid:sysutils/daemontools
TCPSERVER_RUN_DEPENDS=		tcpserver:sysutils/ucspi-tcp

MAKE_ARGS+=	DIET="" CC="${CC}" CXX="${CXX}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCGI}
SED_SCRIPT+=	-e "s|^// \(\#define CGI\).*|\1|"
.endif

# HOPE YOU KNOW WHAT YOU'RE LINKING !
#
# e.g.: if a file foo is a symlink to /etc/passwd and you don't have a
# chroot enviroment then the system-wide /etc/passwd is provided !!!
#
# If the symlink is dangling OR this option is not active the symlink is
# provided as a new http-uri.
#
# e.g.: is foo a symlink to /etc/passwd than the client gets a href to
# http://<vhost>/etc/passwd */

.if ${PORT_OPTIONS:MSYSTEM_SYMLINK_DEREF}
.if empty(PORT_OPTIONS:MDIR_LIST)
IGNORE=	SYSTEM_SYMLINK_DEREF requires the DIR_LIST option
.endif
SED_SCRIPT+=	-e "s|^/\* \(\#define SYSTEM_SYMLINK_DEREF\).*|\1|"
.endif

.if ${PORT_OPTIONS:MDIR_LIST}
SED_SCRIPT+=	-e "s|^/\* \(\#define DIR_LIST\).*|\1|"
.endif

# If a file is not found locally, and $REDIRECT_HOST is set, fnord will
# issue a redirect to strcat($REDIRECT_HOST,uri).  Otherwise, if
# $REDIRECT_URI is set, fnord will issue a redirect to $REDIRECT_URI.
# Only if those fail will a 404 error be returned. */

.if ${PORT_OPTIONS:MOLD_STYLE_REDIRECT}
SED_SCRIPT+=	-e "s|^/\* \(\#define OLD_STYLE_REDIRECT\).*|\1|"
.endif

post-patch:
	@[ -z '${SED_SCRIPT}' ] || \
		 ${REINPLACE_CMD} ${SED_SCRIPT} ${WRKSRC}/httpd.c
	@${REINPLACE_CMD} -e "/strip/d" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fnord ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fnord-conf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/fnord.inetd ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
