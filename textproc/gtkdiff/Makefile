# New ports collection makefile for:	gtkdiff
# Date created:		17 November 1999
# Whom:			Maxim Sobolev
#
# $FreeBSD$
#

PORTNAME=	gtkdiff
PORTVERSION= 	1.0.2
CATEGORIES=	textproc gnome
MASTER_SITES=	http://www.ainet.or.jp/~inoue/software/gtkdiff/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}"

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		gtkdiff.1

.include <bsd.port.mk>
