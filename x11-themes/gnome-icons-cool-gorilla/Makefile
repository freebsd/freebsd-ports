# New ports collection makefile for:	Gnome iconset CoolGorilla
# Date created:				29 Feb 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	cool-gorilla
PORTVERSION=	20030726
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://tmclaugh.freeshell.org/files/ports/distfiles/
DISTNAME=	ICON-CoolGorilla

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	CoolGorilla Icons for Gnome

NO_PACKAGE=	${REASON}
NO_CDROM=	${REASON}
RESTRICTED=	${REASON}

USE_BZIP2=	yes
WRKSRC=		"${WRKDIR}/CoolGorilla-ICONS"

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
