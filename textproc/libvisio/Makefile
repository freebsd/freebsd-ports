# New ports collection makefile for:	libvisio
# Date created:		2011-09-19
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libvisio
PORTVERSION=	0.0.14
CATEGORIES=	textproc devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/ \
		LOCAL/sunpoet

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing the visio file format structure

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/include/classic_core.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	wpd-0.9.9:${PORTSDIR}/textproc/libwpd \
		wpg-0.2.2:${PORTSDIR}/graphics/libwpg

USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--disable-werror

.include <bsd.port.mk>
