PORTNAME=	libe-book
DISTVERSION=	0.1.3
PORTREVISION=	30
CATEGORIES=	textproc
MASTER_SITES=	SF/libebook/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for import of reflowable e-book formats
WWW=		https://sourceforge.net/projects/libebook/

LICENSE=	MPL20

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string/classification.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		liblangtag.so:devel/liblangtag \
		librevenge-0.0.so:textproc/librevenge

USES=		autoreconf compiler:c++11-lib gmake gnome gperf libtool \
		localbase pathfix pkgconfig tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

CPPFLAGS+=	-DBOOST_ERROR_CODE_HEADER_ONLY

CONFIGURE_ARGS=	--disable-werror --disable-tests

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
