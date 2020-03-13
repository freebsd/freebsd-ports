# $FreeBSD$

PORTNAME=	libvisio
PORTVERSION=	0.1.7
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	LODEV/${PORTNAME}
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing the visio file format structure

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

.include <bsd.port.mk>
