# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

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
		${THEMESBASE}/libthinice.so:${PORTSDIR}/x11-themes/thinice

THEMESBASE=	${LOCALBASE}/lib/gtk/themes/engines

NO_BUILD=	yes

do-install:	# empty

NO_STAGE=	yes
.include <bsd.port.mk>
