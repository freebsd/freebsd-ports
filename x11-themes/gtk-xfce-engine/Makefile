# New ports collection makefile for:	gtk-xfce-engine
# Date Created:				10 October 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtk-xfce-engine
PORTVERSION=	2.1.8
PORTREVISION=	1
CATEGORIES=	x11-toolkits xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/4.0.3/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/4.0.3/xfce-4.0.3/src/ \
		http://changux.homelinux.org/xfce_4.0.3/separate_tars/ \
		http://www.efd.lth.se/~c03bk/xfce4/mirror/tarballs/4.0.3/ \
		http://www.xfce.org/archive/xfce-4.0.3/src/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	An XFCE engine for GTK 2.0

LIB_DEPENDS=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20

USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
