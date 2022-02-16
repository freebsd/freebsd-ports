PORTNAME=	libixion
PORTVERSION=	0.17.0
CATEGORIES=	textproc
MASTER_SITES=	https://kohei.us/files/ixion/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	General purpose formula parser, interpreter, dependency tracker

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mdds>=2.0:devel/mdds
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		autoreconf libtool pkgconfig tar:xz

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB=	VERSION=${PORTVERSION:R}

CONFIGURE_ARGS=	--disable-python

.include <bsd.port.mk>
