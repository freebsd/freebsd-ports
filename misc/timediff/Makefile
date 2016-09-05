# Created by: Naito Yuichiro <naito.yuichiro@gmail.com>
# $FreeBSD$

PORTNAME=	timediff
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Showing time pairs between target timezone and localtime

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	belgianbeer
GH_PROJECT=	timediff

PLIST_FILES=	sbin/timediff

NO_ARCH=	yes
NO_BUILD=	yes

do-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/timediff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/timediff \
	    ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
