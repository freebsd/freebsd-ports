# New ports collection makefile for:	flowcanvas
# Date created:		2008-07-22
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flowcanvas
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	FlowCanvas is an interactive Gtkmm/Gnomecanvasmm widget

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost-libs \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gnomecanvasmm-2.6:${PORTSDIR}/graphics/libgnomecanvasmm26 \
		gvc.5:${PORTSDIR}/graphics/graphviz

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
CONFIGURE_ENV=	"CXXFLAGS=${CFLAGS} -I${LOCALBASE}/include"

.include <bsd.port.mk>
