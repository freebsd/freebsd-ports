# $FreeBSD$

PORTNAME=	libvisio
PORTVERSION=	0.1.5
PORTREVISION=	10
CATEGORIES=	textproc devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/${PORTNAME}/
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing the visio file format structure

LICENSE=	GPLv2+ LGPL21+ MPL11 MPL20
LICENSE_COMB=	dual
LICENSE_FILE_MPL20=	${WRKSRC}/COPYING.MPL

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/include/classic_core.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		librevenge-0.0.so:textproc/librevenge

CONFIGURE_ARGS=	--disable-tests --disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_GNOME=	libxml2
USES=		compiler:c++0x gmake gperf libtool pathfix perl5 pkgconfig tar:xz
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
