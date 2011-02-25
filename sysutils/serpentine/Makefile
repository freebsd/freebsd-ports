# New ports collection makefile for:	serpentine
# Date created:		2005-06-25
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/serpentine/Makefile,v 1.4 2006/08/31 05:21:45 marcus Exp $

PORTNAME=	serpentine
PORTVERSION=	0.7
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome Audio Cd Burner

BUILD_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml
RUN_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pygnomedesktop intlhack
USE_GMAKE=	yes
USE_GSTREAMER=	core gnomevfs python
USE_PYTHON=	2.4+

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPTIONS=	MUINE "Cd-Burner Plugin for muine audio player" Off
.endif

.include <bsd.port.options.mk>

.if defined(WITH_MUINE)
BUILD_DEPENDS+=	muine:${PORTSDIR}/audio/muine
RUN_DEPENDS+=	muine:${PORTSDIR}/audio/muine
PLIST_SUB+=	MUINE=""
CONFIGURE_ARGS+=	--enable-muine
.else
PLIST_SUB+=	MUINE="@comment "
.endif

.include <bsd.port.post.mk>
