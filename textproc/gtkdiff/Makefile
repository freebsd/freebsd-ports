# New ports collection makefile for:	gtkdiff
# Version required:	1.0.1
# Date created:		17 November 1999
# Whom:			Maxim Sobolev
#
# $FreeBSD$
#

DISTNAME=	gtkdiff-1.0.1
CATEGORIES=	textproc gnome
MASTER_SITES=	http://www.ainet.or.jp/~inoue/software/gtkdiff/

MAINTAINER=	sobomax@altavista.net

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}"

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
