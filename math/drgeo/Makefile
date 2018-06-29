# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drgeo
PORTVERSION=	1.1.0
PORTREVISION=	20
CATEGORIES=	math
MASTER_SITES=	SF/ofset/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GTK interactive geometry software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to compile: ./geo/libgeo.a: multiple definition of drgeoDialogData

LIB_DEPENDS=	libguile.so:lang/guile

USES=		gettext gmake localbase:ldflags pkgconfig pathfix
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intlhack libglade2

CXXFLAGS+=	-Wno-reserved-user-defined-literal

PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/plugin/drgeo/progs/tm_drgeo

.include <bsd.port.mk>
