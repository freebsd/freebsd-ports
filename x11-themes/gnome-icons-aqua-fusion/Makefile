# New ports collection makefile for:	Gnome iconset AquaFusion
# Date created:				29 Feb 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	aqua-fusion
PORTVERSION=	20030216
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	teams/art.gnome.org/archive/themes/icon
DISTNAME=	ICON-AquaFusion

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	AquaFusion Icons for Gnome

NO_PACKAGE=	${REASON}
NO_CDROM=	${REASON}
RESTRICTED=	${REASON}

USE_BZIP2=	yes
WRKSRC=		"${WRKDIR}/AquaFusion"

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
