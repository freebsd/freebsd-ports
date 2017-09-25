# $FreeBSD$

PORTNAME=	libe-book
PORTVERSION=	0.1.2
PORTREVISION=	15
CATEGORIES=	textproc
MASTER_SITES=	SF/libebook/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for import of reflowable e-book formats

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		librevenge-0.0.so:textproc/librevenge

OPTIONS_DEFINE=	DOCS

USE_GNOME=	libxml2

USES=		compiler:c++11-lang gmake gperf libtool pathfix pkgconfig \
		tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-werror --disable-tests
CPPFLAGS+=	-I${LOCALBASE}/include -DBOOST_ERROR_CODE_HEADER_ONLY

PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
