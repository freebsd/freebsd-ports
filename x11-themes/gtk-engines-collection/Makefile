# New ports collection makefile for:   gtk-engines-collection
# Date created:        13 June 2000
# Whom:                Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-engines-collection
PORTVERSION= 	1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	sobomax@FreeBSD.org

# I intentionally did not put gtk-engines in the list below because
# this package is uterly buggy.
RUN_DEPENDS=	${THEMESBASE}/libclean.so:${PORTSDIR}/x11-toolkits/clean-theme-gtk \
		${THEMESBASE}/libgnomelook.so:${PORTSDIR}/x11-toolkits/gnome-look \
		${THEMESBASE}/libstep.so:${PORTSDIR}/x11-toolkits/gtkstep \
		${THEMESBASE}/libsteppastel.so:${PORTSDIR}/x11-toolkits/gtkstep-pastel \
		${THEMESBASE}/libthinice.so:${PORTSDIR}/x11-toolkits/thinice \
		${THEMESBASE}/libxeno.so:${PORTSDIR}/x11-toolkits/xenophilia

THEMESBASE=	${X11BASE}/lib/gtk/themes/engines

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
