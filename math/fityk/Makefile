# ex:ts=8
# Ports collection makefile for:	fityk
# Date created:			Mar 8, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fityk
PORTVERSION=	0.4.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free peak fitting software

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimization
USE_GMAKE=	yes

MAN1=	fityk.1

.include <bsd.port.mk>
