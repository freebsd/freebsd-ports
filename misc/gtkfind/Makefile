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

BROKEN=		"Missing dependency on xterm"

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

MAN1=		gtkfind.1 mktmp.1

.include <bsd.port.mk>
