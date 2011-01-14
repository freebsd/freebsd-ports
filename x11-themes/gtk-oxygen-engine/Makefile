# New ports collection makefile for:	gtk-oxygen-engine
# Date created:		2010-12-14
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oxygen
PORTVERSION=	1.0.1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-gtk/${PORTVERSION}/src/
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine
DISTNAME=	${PORTNAME}-gtk-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Oxygen-Gtk engine and theme

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USE_BZIP2=	yes
USE_GNOME=	gtk20 pkgconfig
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
