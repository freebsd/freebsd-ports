# Created by: Naito Yuichiro <naito.yuichiro@gmail.com>
# $FreeBSD$

PORTNAME=	tzdiff
PORTVERSION=	0.9
CATEGORIES=	misc

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Showing time pairs between target timezone and localtime

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	belgianbeer
GH_PROJECT=	tzdiff

PLIST_FILES=	bin/tzdiff

NO_ARCH=	yes
NO_BUILD=	yes

do-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/tzdiff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tzdiff \
	    ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
