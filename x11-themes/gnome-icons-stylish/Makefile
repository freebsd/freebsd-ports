# New ports collection makefile for:	Gnome iconset Stylish
# Date created:				29 Feb 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	stylish
PORTVERSION=	20030129
CATEGORIES=	x11-themes gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	teams/art.gnome.org/themes/icon
DISTNAME=	ICON-Stylish

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Stylish Icons for Gnome

NO_PACKAGE=	${REASON}
NO_CDROM=	${REASON}
RESTRICTED=	${REASON}

WRKSRC=		"${WRKDIR}/${PORTNAME}"

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
