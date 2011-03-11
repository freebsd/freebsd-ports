# New ports collection makefile for:	gtk-engines-collection
# Date created:				13 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-engines-collection
PORTVERSION=	1.8
PORTREVISION=	7
CATEGORIES=	x11-themes
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "meta-port" for the collection of several GTK+ theme engines

RUN_DEPENDS=	${THEMESBASE}/libgnomelook.so:${PORTSDIR}/x11-themes/gnome-look \
		${THEMESBASE}/libpixmap.so:${PORTSDIR}/x11-themes/gtk-engines \
		${THEMESBASE}/libqnx.so:${PORTSDIR}/x11-themes/gtk-qn-x11-theme \
		${THEMESBASE}/libstep.so:${PORTSDIR}/x11-themes/gtkstep \
		${THEMESBASE}/libsteppastel.so:${PORTSDIR}/x11-themes/gtkstep-pastel \
		${THEMESBASE}/libzenith.so:${PORTSDIR}/x11-themes/gtk-zenith-theme \
		${THEMESBASE}/libthinice.so:${PORTSDIR}/x11-themes/thinice \
		${THEMESBASE}/libwhistler.so:${PORTSDIR}/x11-themes/whistlerk

THEMESBASE=	${LOCALBASE}/lib/gtk/themes/engines

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
