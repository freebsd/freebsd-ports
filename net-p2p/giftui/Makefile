# New ports collection makefile for: giFTui
# Date Created:			23 May 2004
# Whom:				Joel Diaz <joeldiaz@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	giFTui
PORTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	giftui
DISTNAME=	giftui-0.4.1

MAINTAINER=	joeldiaz@bellsouth.net
COMMENT=	GTK2 client for giFT daemon

LIB_DEPENDS=	gift.0:${PORTSDIR}/net/gift

BROKEN=	"Needs an update for GTK+ 2.6"

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gconf2 gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
