# New ports collection makefile for:	gtkfind
# Date created:				28 Sept 1998
# Whom:					Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	gtkfind
PORTVERSION=	1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.oz.net/~mattg/
# metalab hasn't caught up yet...
#		${MASTER_SITE_SUNSITE}
#MASTER_SITE_SUBDIR=	X11/gtkbuffet/apps/gtkfind

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

MAN1=		gtkfind.1 mktmp.1
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  GTK_CONFIG="${GTK_CONFIG}"
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_GMAKE=	yes

.include <bsd.port.mk>
