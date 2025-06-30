PORTNAME=	libvisio
PORTVERSION=	0.1.8
PORTREVISION=	2
CATEGORIES=	textproc devel
MASTER_SITES=	LODEV/${PORTNAME}
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing the visio file format structure
WWW=		https://wiki.documentfoundation.org/DLP/Libraries/libvisio

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING.MPL

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/include/classic_core.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		librevenge-0.0.so:textproc/librevenge

CONFIGURE_ARGS=	--disable-tests --disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gmake gnome gperf libtool pathfix perl5 \
		pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_GNOME=	libxml2
INSTALL_TARGET=	install-strip

PLIST_SUB=	LIBVERSION=1.0.${PORTVERSION:E}

.include <bsd.port.mk>
