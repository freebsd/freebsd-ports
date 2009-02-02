# New ports collection makefile for:	Gnome iconset Noia-Full
# Date created:				29 Feb 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	noia-full
PORTVERSION=	20041102
PORTREVISION=	2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	teams/art.gnome.org/archive/themes/icon
DISTNAME=	ICON-Noia

MAINTAINER=	tmclaugh@FreeBSD.org
COMMENT=	Noia Icons for Gnome

RESTRICTED=	${REASON}

USE_BZIP2=	yes
WRKSRC=		"${WRKDIR}/Noia"

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
