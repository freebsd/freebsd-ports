# $FreeBSD$

PORTNAME=	libstaroffice
PORTVERSION=	0.0.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	LODEV
MASTER_SITE_SUBDIR=	#

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library to build a filter for old StarOffice's documents

LICENSE=	LGPL21+ MPL20
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

BROKEN_powerpc64=	fails to configure: Could not find Boost implementation of shared_ptr

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig tar:xz

CONFIGURE_ARGS=	--without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
