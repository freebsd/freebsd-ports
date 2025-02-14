PORTNAME=	libmspub
DISTVERSION=	0.1.4
PORTREVISION=	25
CATEGORIES=	print graphics devel
MASTER_SITES=	LODEV/${PORTNAME}
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Microsoft Publisher file format
WWW=		https://wiki.documentfoundation.org/DLP/Libraries/libmspub

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING.MPL

BUILD_DEPENDS=	${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		librevenge-0.0.so:textproc/librevenge

USES=		autoreconf compiler:c++11-lib libtool localbase pathfix \
		pkgconfig tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-werror --without-docs

.include <bsd.port.mk>
