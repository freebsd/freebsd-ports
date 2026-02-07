PORTNAME=	libartnet
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ArtNet protocol to transfer DMX data controlling theater equipment
WWW=		https://www.openlighting.org/libartnet-main/ \
		https://github.com/atlesn/libartnet

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	atlesn

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
