# New ports collection makefile for:	gtk-xfce-engine
# Date Created:				10 October 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtk-xfce-engine
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits xfce
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xfce
DISTNAME=	gtk-xfce-engine-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An XFCE engine for GTK 2.0

LIB_DEPENDS=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20

WRKSRC=		${WRKDIR}/gtk-xfce-engine-${PORTVERSION}

USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
