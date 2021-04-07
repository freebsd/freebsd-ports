PORTNAME=	libabw
PORTVERSION=	0.1.3
CATEGORIES=	textproc
MASTER_SITES=	LODEV/${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library providing ability to interpret Abiword documents

LICENSE=	MPL20

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:devel/boost-libs
LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

USES=		compiler:c++11-lib gnome gperf libtool localbase pathfix perl5 pkgconfig \
		tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_PERL5=	build
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--without-docs

.include <bsd.port.mk>
