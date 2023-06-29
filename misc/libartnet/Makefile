PORTNAME=	libartnet
DISTVERSION=	1.1.2
CATEGORIES=	misc
MASTER_SITES=	https://github.com/OpenLightingProject/libartnet/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ArtNet protocol to transfer DMX data controlling theater equipment
WWW=		https://www.openlighting.org/libartnet-main/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
