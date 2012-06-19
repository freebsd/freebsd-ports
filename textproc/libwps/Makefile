# New ports collection makefile for:	libwps
# Date created:		2008-04-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwps
PORTVERSION=	0.2.7
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	A Microsoft file word processor format import filter library

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	wpd-0.9:${PORTSDIR}/textproc/libwpd

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack gnomeprefix ltverhack
USE_LDCONFIG=	yes

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ARGS+=--without-docs
.endif

.include <bsd.port.mk>
