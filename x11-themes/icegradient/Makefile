# New ports collection makefile for:	icegradient
# Date Created:				21 August 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icegradient
PORTVERSION=	200012290259
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.themes.org/pub/themes/gtk/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax
DISTNAME=	IceGradient-1.2.x-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ gradient theme engine based on ThinIce

WRKSRC=		${WRKDIR}/gtk-${PORTNAME}-0.0.5

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
