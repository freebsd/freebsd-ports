# New ports collection makefile for:	Gnome iconset
# Date created:				29 Feb 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/Makefile.icons for it.

PORTNAME=	gnome-icons
PORTVERSION=	20040229
CATEGORIES=	x11-themes gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Meta-port for Gnome iconsets

RUN_DEPENDS=	${X11BASE}/share/icons/aqua-fusion/index.theme:${PORTSDIR}/x11-themes/gnome-icons-aqua-fusion \
		${X11BASE}/share/icons/cool-gorilla/index.theme:${PORTSDIR}/x11-themes/gnome-icons-cool-gorilla \
		${X11BASE}/share/icons/crystal/index.theme:${PORTSDIR}/x11-themes/gnome-icons-crystal \
		${X11BASE}/share/icons/gentoo-test/index.theme:${PORTSDIR}/x11-themes/gnome-icons-gentoo-test \
		${X11BASE}/share/icons/iris/index.theme:${PORTSDIR}/x11-themes/gnome-icons-iris \
		${X11BASE}/share/icons/noia-full/index.theme:${PORTSDIR}/x11-themes/gnome-icons-noia-full \
		${X11BASE}/share/icons/noia-warm/index.theme:${PORTSDIR}/x11-themes/gnome-icons-noia-warm \
		${X11BASE}/share/icons/refined/index.theme:${PORTSDIR}/x11-themes/gnome-icons-refined \
		${X11BASE}/share/icons/slick/index.theme:${PORTSDIR}/x11-themes/gnome-icons-slick \
		${X11BASE}/share/icons/snow-apple/index.theme:${PORTSDIR}/x11-themes/gnome-icons-snow-apple \
		${X11BASE}/share/icons/stylish/index.theme:${PORTSDIR}/x11-themes/gnome-icons-stylish \
		${X11BASE}/share/icons/ximian-south/index.theme:${PORTSDIR}/x11-themes/gnome-icons-ximian-south

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
