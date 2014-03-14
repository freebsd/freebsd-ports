# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	gnome-icons
PORTVERSION=	20060914
PORTREVISION=	4
CATEGORIES=	x11-themes gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meta-port for Gnome iconsets

RUN_DEPENDS=	${LOCALBASE}/share/icons/AquaFusion/index.theme:${PORTSDIR}/x11-themes/gnome-icons-aqua-fusion \
		${LOCALBASE}/share/icons/CfG-Crystal-SVG-1.2.0/index.theme:${PORTSDIR}/x11-themes/gnome-icons-crystal \
		${LOCALBASE}/share/icons/Gentoo-test/index.theme:${PORTSDIR}/x11-themes/gnome-icons-gentoo-test \
		${LOCALBASE}/share/icons/Iris/index.theme:${PORTSDIR}/x11-themes/gnome-icons-iris \
		${LOCALBASE}/share/icons/Lila/index.theme:${PORTSDIR}/x11-themes/gnome-icons-lila \
		${LOCALBASE}/share/icons/Noia/index.theme:${PORTSDIR}/x11-themes/gnome-icons-noia-full \
		${LOCALBASE}/share/icons/NoiaWarm/index.theme:${PORTSDIR}/x11-themes/gnome-icons-noia-warm \
		${LOCALBASE}/share/icons/gnome-rh8/index.theme:${PORTSDIR}/x11-themes/gnome-icons-refined \
		${LOCALBASE}/share/icons/Slick/index.theme:${PORTSDIR}/x11-themes/gnome-icons-slick \
		${LOCALBASE}/share/icons/Snow-Apple/index.theme:${PORTSDIR}/x11-themes/gnome-icons-snow-apple \
		${LOCALBASE}/share/icons/stylish/index.theme:${PORTSDIR}/x11-themes/gnome-icons-stylish \
		${LOCALBASE}/share/icons/ximian-south/index.theme:${PORTSDIR}/x11-themes/gnome-icons-ximian-south \
		${LOCALBASE}/share/icons/Lila/index.theme:${PORTSDIR}/x11-themes/gnome-icons-lila

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
