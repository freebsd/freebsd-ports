# New ports collection makefile for:	gtk-engines-collection
# Date created:				13 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-engines-collection
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "meta-port" for the collection of several GTK+ theme engines

RUN_DEPENDS=	${THEMESBASE}/libbuffy.so:${THEMESPORTDIR}/buffy \
		${THEMESBASE}/libclean.so:${THEMESPORTDIR}/clean-theme-gtk \
		${THEMESBASE}/libcolorstep.so:${THEMESPORTDIR}/colorstep \
		${THEMESBASE}/libengradient.so:${THEMESPORTDIR}/engradient \
		${THEMESBASE}/libflat.so:${THEMESPORTDIR}/gtk-flat-theme \
		${THEMESBASE}/libgnomelook.so:${THEMESPORTDIR}/gnome-look \
		${THEMESBASE}/libgtkbe.so:${THEMESPORTDIR}/gtkbe \
		${THEMESBASE}/libicegradient.so:${THEMESPORTDIR}/icegradient \
		${THEMESBASE}/libmac2.so:${THEMESPORTDIR}/gtk-Mac2-theme \
		${THEMESBASE}/libpixmap.so:${THEMESPORTDIR}/gtk-engines \
		${THEMESBASE}/libqnx.so:${THEMESPORTDIR}/gtk-qn-x11-theme \
		${THEMESBASE}/libstep.so:${THEMESPORTDIR}/gtkstep \
		${THEMESBASE}/libsteppastel.so:${THEMESPORTDIR}/gtkstep-pastel \
		${THEMESBASE}/libzenith.so:${THEMESPORTDIR}/gtk-zenith-theme \
		${THEMESBASE}/libthinice.so:${THEMESPORTDIR}/thinice \
		${THEMESBASE}/libXenoStep.so:${THEMESPORTDIR}/xenostep \
		${THEMESBASE}/libxeno.so:${THEMESPORTDIR}/xenophilia \
		${THEMESBASE}/libwhistler.so:${THEMESPORTDIR}/whistlerk

THEMESBASE=	${X11BASE}/lib/gtk/themes/engines
THEMESPORTDIR=	${PORTSDIR}/x11-toolkits

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
