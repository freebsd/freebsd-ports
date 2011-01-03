# New ports collection makefile for:	libwps
# Date created:		2008-04-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwps
PORTVERSION=	0.2.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A Microsoft file word processor format import filter library

LIB_DEPENDS=	wpd-0.9.9:${PORTSDIR}/textproc/libwpd

LICENSE=	LGPL21

USE_AUTOTOOLS=	libtool
USE_GNOME=     gnomeprefix gnomehack ltverhack
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--without-docs
.else
BUILD_DEPENDS+=		doxygen:${PORTSDIR}/devel/doxygen
.endif

.include <bsd.port.post.mk>
