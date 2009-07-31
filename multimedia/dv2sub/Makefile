# New ports collection makefile for:   dv2sub
# Date created:        Fri Jan 18
# Whom:                Phil Oleson
#
# $FreeBSD$
#

PORTNAME=	dv2sub
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	oz@nixil.net
COMMENT=	Extracts info or subtitles from DV stream

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv

GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig

PLIST_FILES=	bin/dv2sub
MAN1=		dv2sub.1

.include <bsd.port.mk>
