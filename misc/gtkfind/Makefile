# New ports collection makefile for:   gtkfind
# Version required:    0.9
# Date created:        28 Sept 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.2 1998/11/18 19:25:17 billf Exp $
#

DISTNAME=	gtkfind-0.9
CATEGORIES=	misc
MASTER_SITES=	http://www.oz.net/~mattg/

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=	gtk10.1:${PORTSDIR}/x11-toolkits/gtk10

ALL_TARGET=	gtkfind
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk10-config"

MAN1=		gtkfind.1

.include <bsd.port.mk>
