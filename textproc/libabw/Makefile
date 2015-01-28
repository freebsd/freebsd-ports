# $FreeBSD$

PORTNAME=	libabw
PORTVERSION=	0.1.1
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/${PORTNAME}/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library providing ability to interpret Abiword documents

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	librevenge-0.0.so:${PORTSDIR}/textproc/librevenge

USES=		gperf perl5 libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_PERL5=	build
INSTALL_TARGET=	install-strip

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	-disable-werror --without-docs

.include <bsd.port.mk>
