PORTNAME=	libixion
DISTVERSION=	0.19.0
CATEGORIES=	textproc
MASTER_SITES=	https://kohei.us/files/ixion/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	General purpose formula parser, interpreter, dependency tracker
WWW=		https://gitlab.com/ixion/ixion

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mdds>=2.1:devel/mdds
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		libtool localbase pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB=	VERSION=0.18
#PLIST_SUB=	VERSION=${DISTVERSION:R}

CONFIGURE_ARGS=	--disable-python

.include <bsd.port.mk>
