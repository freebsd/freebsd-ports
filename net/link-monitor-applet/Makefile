# New ports collection makefile for:	link-monitor-applet
# Date created:			27 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		link-monitor-applet
PORTVERSION=		1.3
PORTREVISION=	3
CATEGORIES=		net ipv6
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	link-monitor

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		A GNOME applet displaying the round-trip time to one or more hosts

USE_X_PREFIX=		yes
USE_GNOME=		gnomehack gnomeprefix gnomepanel eel2
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -Wl,-export-dynamic"

GCONF_SCHEMAS=		link-monitor-applet.schemas
INSTALLS_OMF=		yes

.include <bsd.port.mk>
