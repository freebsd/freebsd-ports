# New ports collection makefile for:	gtk-xfce-engine
# Date Created:				10 October 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtk-xfce-engine
PORTVERSION=	2.0.10
CATEGORIES=	x11-toolkits
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xfce
DISTNAME=	gtk-xfce-engine-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20

WRKSRC=		${WRKDIR}/gtk-xfce-engine-${PORTVERSION}

USE_GMAKE=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
