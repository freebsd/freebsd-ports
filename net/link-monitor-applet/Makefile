# New ports collection makefile for:	link-monitor-applet
# Date created:			27 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	link-monitor-applet
PORTVERSION=	2.1
PORTREVISION=	8
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	link-monitor

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME applet displaying the round-trip time to one or more hosts

LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

USE_GNOME=	gnomehack gnomeprefix gnomepanel eel2 librsvg2 libgnomeui
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	link-monitor-applet.schemas
INSTALLS_OMF=	yes

.include <bsd.port.mk>
