# New ports collection makefile for:	gtk-Mac2-theme
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-Mac2-theme
PORTVERSION= 	200003050858
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.themes.org/pub/themes/gtk/
DISTNAME=	Mac2-1.2.x-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
