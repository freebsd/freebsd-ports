# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drgeo
PORTVERSION=	1.1.0
PORTREVISION=	21
CATEGORIES=	math
MASTER_SITES=	SF/ofset/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GTK interactive geometry software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libguile.so:lang/guile

USES=		compiler:c++11-lang gettext gmake gnome localbase:ldflags \
		pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intlhack libglade2

CXXFLAGS+=	-Wno-reserved-user-defined-literal

PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/plugin/drgeo/progs/tm_drgeo

.include <bsd.port.mk>
