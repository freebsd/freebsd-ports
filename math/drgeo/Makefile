# New ports collection makefile for:	drgenius
# Date created:				11 January 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drgeo
PORTVERSION=	0.9.11
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ofset

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK interactive geometry sofware

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libglade2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
