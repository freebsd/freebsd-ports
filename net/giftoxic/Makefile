# New ports collection makefile for: giFToxic
# Date Created:			23 December 2003
# Whom:				Joel Diaz <joeldiaz@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	giFToxic
PORTVERSION=	0.0.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	giftoxic

MAINTAINER=	joeldiaz@bellsouth.net
COMMENT=	GTK2 client for giFT

LIB_DEPENDS=	gift.0:${PORTSDIR}/net/gift

USE_X_PREFIX=	yes
USE_GETOPT_LONG=	yes
USE_GNOME=	gtk20 gnomeprefix gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-included-gettext

.include <bsd.port.mk>
