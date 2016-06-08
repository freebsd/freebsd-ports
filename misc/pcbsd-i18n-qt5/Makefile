# $FreeBSD$

PORTNAME=	pcbsd-i18n-qt5
PORTVERSION=	20160312
CATEGORIES=	misc

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Qt5 i18n Support

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	pcbsd-base>=0:${PORTSDIR}/misc/pcbsd-base

USE_QT5=        buildtools linguist
USES=		tar:xz

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	pcbsd-translate
GH_TAGNAME=     8156abdd079866f2e2a141ecc1d74d4a1a2615ec

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pcbsd/i18n
	cd ${WRKSRC}/scripts && ${SH} ./mkrelease.sh ${STAGEDIR}${PREFIX}/share/pcbsd/i18n

.include <bsd.port.mk>
