# New ports collection makefile for:	asio
# Date created:		2010-11-14
# Whom:			Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asio
PORTVERSION=	1.4.5
CATEGORIES=	net devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20(Stable)/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Cross-platform C++ library for network and low-level I/O programming

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include

.include <bsd.port.mk>
