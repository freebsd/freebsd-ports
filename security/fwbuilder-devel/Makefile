# New ports collection makefile for:	fwbuilder
# Date Created:				3 Feb 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fwbuilder
PORTVERSION=	0.8.7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml \
		gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
USE_GNOMELIBS=	yes
WITHOUT_ESOUND=	yes

.include <bsd.port.mk>
