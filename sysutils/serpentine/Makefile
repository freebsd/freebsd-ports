# New ports collection makefile for:	serpentine
# Date created:		2005-06-25
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/serpentine/Makefile,v 1.4 2006/08/31 05:21:45 marcus Exp $

PORTNAME=	serpentine
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Gnome Audio Cd Burner

BUILD_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml
RUN_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pygnomedesktop intlhack
USE_GMAKE=	yes
USE_GSTREAMER=	core gnomevfs python
USE_PYTHON=	2.4+

OPTIONS=	MUINE "Cd-Burner Plugin for muine audio player (i386 only)" Off

.include <bsd.port.pre.mk>

.if (defined(WITH_MUINE) || exists(${LOCALBASE}/bin/muine)) && ${ARCH}=="i386"
BUILD_DEPENDS+=	muine:${PORTSDIR}/audio/muine
RUN_DEPENDS+=	muine:${PORTSDIR}/audio/muine
PLIST_SUB+=	MUINE=""
CONFIGURE_ARGS+=	--enable-muine
.else
PLIST_SUB+=	MUINE="@comment "
.endif

.include <bsd.port.post.mk>
