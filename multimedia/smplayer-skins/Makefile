PORTNAME=	smplayer-skins
DISTVERSION=	20.11.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia audio kde
MASTER_SITES=	SF/smplayer/SMPlayer-skins/${PORTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Skins for SMPlayer (Skinnable GUI)
WWW=		http://smplayer.sourceforge.net/

USES=		qt:5 tar:bzip2
USE_QT=		buildtools:build

NO_ARCH=	yes

DATADIR=	${PREFIX}/share/smplayer

BINARY_ALIAS=	rcc=${RCC}

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
