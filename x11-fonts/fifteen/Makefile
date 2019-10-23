# $FreeBSD$

PORTNAME=	fifteen
PORTVERSION=	20150410
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://fontlibrary.org/assets/downloads/${PORTNAME}/c1556403ec283a1b5a23ad483af659f9/
DISTNAME=	${PORTNAME}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Narrow monospaced fonts

LICENSE=	OFL11

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.bdf *.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
