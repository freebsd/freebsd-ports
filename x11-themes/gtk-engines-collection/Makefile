# New ports collection makefile for:	gtk-engines-collection
# Date created:				13 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-engines-collection
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "meta-port" for the collection of several GTK+ theme engines

RUN_DEPENDS=	${THEMESBASE}/libbuffy.so:${PORTSDIR}/x11-themes/buffy \
		${THEMESBASE}/libclean.so:${PORTSDIR}/x11-themes/clean-theme-gtk \
		${THEMESBASE}/libcolorstep.so:${PORTSDIR}/x11-themes/colorstep \
		${THEMESBASE}/libengradient.so:${PORTSDIR}/x11-themes/engradient \
		${THEMESBASE}/libflat.so:${PORTSDIR}/x11-themes/gtk-flat-theme \
		${THEMESBASE}/libgnomelook.so:${PORTSDIR}/x11-themes/gnome-look \
		${THEMESBASE}/libgtkbe.so:${PORTSDIR}/x11-themes/gtkbe \
		${THEMESBASE}/libicegradient.so:${PORTSDIR}/x11-themes/icegradient \
		${THEMESBASE}/libmac2.so:${PORTSDIR}/x11-themes/gtk-Mac2-theme \
		${THEMESBASE}/libpixmap.so:${PORTSDIR}/x11-themes/gtk-engines \
		${THEMESBASE}/libqnx.so:${PORTSDIR}/x11-themes/gtk-qn-x11-theme \
		${THEMESBASE}/libstep.so:${PORTSDIR}/x11-themes/gtkstep \
		${THEMESBASE}/libsteppastel.so:${PORTSDIR}/x11-themes/gtkstep-pastel \
		${THEMESBASE}/libzenith.so:${PORTSDIR}/x11-themes/gtk-zenith-theme \
		${THEMESBASE}/libthinice.so:${PORTSDIR}/x11-themes/thinice \
		${THEMESBASE}/libXenoStep.so:${PORTSDIR}/x11-themes/xenostep \
		${THEMESBASE}/libxeno.so:${PORTSDIR}/x11-themes/xenophilia \
		${THEMESBASE}/libwhistler.so:${PORTSDIR}/x11-themes/whistlerk

THEMESBASE=	${X11BASE}/lib/gtk/themes/engines

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
