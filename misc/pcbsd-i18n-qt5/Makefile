# $FreeBSD$

PORTNAME=	pcbsd-i18n-qt5
PORTVERSION=	20151106
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
GH_TAGNAME=     fdf7666c7cc07786b3987d2a8b135913440773dd

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pcbsd/i18n
	cd ${WRKSRC}/scripts && ${SH} ./mkrelease.sh ${STAGEDIR}${PREFIX}/share/pcbsd/i18n

.include <bsd.port.mk>
