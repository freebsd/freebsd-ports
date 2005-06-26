# New ports collection makefile for:	fnord
# Date created:				May 23 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fnord
PORTVERSION=	1.9
CATEGORIES=	www
MASTER_SITES=	http://www.fefe.de/fnord/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Small and fast webserver with CGI-capability

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools \
		tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/fnord \
		bin/fnord-conf

OPTIONS=	CGI "Enable CGI support" on \
		DIR_LIST "Enable directory listing" on \
		SYSTEM_SYMLINK_DEREF "Enable system symlink (needs DIR_LIST)" off \
		OLD_STYLE_REDIRECT "Enable old style redirection" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CGI)
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

.if defined(WITH_SYSTEM_SYMLINK_DEREF)
.if defined(WITHOUT_DIR_LIST)
IGNORE=	SYSTEM_SYMLINK_DEREF has no effect if DIR_LIST is not enabled
.endif
SED_SCRIPT+=	-e "s|^/\* \(\#define SYSTEM_SYMLINK_DEREF\).*|\1|"
.endif

.if !defined(WITHOUT_DIR_LIST)
SED_SCRIPT+=	-e "s|^/\* \(\#define DIR_LIST\).*|\1|"
.endif

# If a file is not found locally, and $REDIRECT_HOST is set, fnord will
# issue a redirect to strcat($REDIRECT_HOST,uri).  Otherwise, if
# $REDIRECT_URI is set, fnord will issue a redirect to $REDIRECT_URI.
# Only if those fail will a 404 error be returned. */

.if defined(WITH_OLD_STYLE_REDIRECT)
SED_SCRIPT+=	-e "s|^/\* \(\#define OLD_STYLE_REDIRECT\).*|\1|"
.endif

post-patch:
	[ -z '${SED_SCRIPT}' ] || \
		 ${REINPLACE_CMD} ${SED_SCRIPT} ${WRKSRC}/httpd.c

do-build:
	cd ${WRKSRC}; ${GMAKE} DIET=""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fnord ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/fnord-conf ${PREFIX}/bin/

.include <bsd.port.post.mk>
