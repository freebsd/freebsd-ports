# $FreeBSD$

PORTNAME=	libstaroffice
PORTVERSION=	0.0.6
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	LODEV
MASTER_SITE_SUBDIR=	#

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library to build a filter for old StarOffice's documents

LICENSE=	LGPL21+ MPL20
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

USES=		compiler:c++11-lib libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
