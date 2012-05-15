# New ports collection makefile for:	libwps
# Date created:		2008-04-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwps
PORTVERSION=	0.2.6
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	A Microsoft file word processor format import filter library

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	wpd-0.9.9:${PORTSDIR}/textproc/libwpd

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack gnomeprefix ltverhack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--disable-werror

PORTDOCS=	*

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--without-docs
.else
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

.include <bsd.port.mk>
