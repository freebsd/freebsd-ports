# New ports collection makefile for:	Gnome iconset
# Date created:				29 Feb 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	gnome-icons
PORTVERSION=	20040229
CATEGORIES=	x11-themes gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Meta-port for Gnome iconsets

RUN_DEPENDS=	${X11BASE}/share/icons/AquaFusion/index.theme:${PORTSDIR}/x11-themes/gnome-icons-aqua-fusion \
		${X11BASE}/share/icons/CoolGorilla-ICONS/index.theme:${PORTSDIR}/x11-themes/gnome-icons-cool-gorilla \
		${X11BASE}/share/icons/CfG-Crystal-SVG-1.2.0/index.theme:${PORTSDIR}/x11-themes/gnome-icons-crystal \
		${X11BASE}/share/icons/Gentoo-test/index.theme:${PORTSDIR}/x11-themes/gnome-icons-gentoo-test \
		${X11BASE}/share/icons/Iris/index.theme:${PORTSDIR}/x11-themes/gnome-icons-iris \
		${X11BASE}/share/icons/Noia/index.theme:${PORTSDIR}/x11-themes/gnome-icons-noia-full \
		${X11BASE}/share/icons/NoiaWarm/index.theme:${PORTSDIR}/x11-themes/gnome-icons-noia-warm \
		${X11BASE}/share/icons/gnome-rh8/index.theme:${PORTSDIR}/x11-themes/gnome-icons-refined \
		${X11BASE}/share/icons/Slick/index.theme:${PORTSDIR}/x11-themes/gnome-icons-slick \
		${X11BASE}/share/icons/Snow-Apple/index.theme:${PORTSDIR}/x11-themes/gnome-icons-snow-apple \
		${X11BASE}/share/icons/stylish/index.theme:${PORTSDIR}/x11-themes/gnome-icons-stylish \
		${X11BASE}/share/icons/ximian-south/index.theme:${PORTSDIR}/x11-themes/gnome-icons-ximian-south \
		${X11BASE}/share/icons/Lila/index.theme:${PORTSDIR}/x11-themes/gnome-icons-lila

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
