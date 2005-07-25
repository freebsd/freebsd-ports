# New ports collection makefile for:	Gnome iconset Refined
# Date created:				29 Feb 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	refined
PORTVERSION=	20030203
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	teams/art.gnome.org/archive/themes/icon
DISTNAME=	ICON-Gnome-RH8

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Refined Icons for Gnome

NO_PACKAGE=	${REASON}
NO_CDROM=	${REASON}
RESTRICTED=	${REASON}

WRKSRC=		"${WRKDIR}/gnome-rh8"

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
