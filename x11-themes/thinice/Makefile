# New ports collection makefile for:	thinice
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thinice
PORTVERSION=	1.0.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_THEMES} \
		http://www.ing.umu.se/~stric/theme/
MASTER_SITE_SUBDIR=	gtk
DISTNAME=	ThinIce-1.2.x-200104091453
#DISTNAME=	gtk-${PORTNAME}-theme-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/gtk-${PORTNAME}-theme-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes

.include <bsd.port.mk>
