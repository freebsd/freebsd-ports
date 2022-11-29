PORTNAME=	libuninameslist
DISTVERSION=	20221022
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/fontforge/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-dist-${DISTVERSION}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Library of Unicode annotation data
WWW=		https://github.com/fontforge/libuninameslist

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=	FRENCH
OPTIONS_DEFAULT=FRENCH
OPTIONS_SUB=yes

FRENCH_DESC=	Build French library
FRENCH_CONFIGURE_ENABLE=	frenchlib

.include <bsd.port.mk>
