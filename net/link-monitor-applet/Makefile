# New ports collection makefile for:	link-monitor-applet
# Date created:			27 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		link-monitor-applet
PORTVERSION=		0.99
CATEGORIES=		net ipv6
MASTER_SITES=		http://lefort.be.eu.org/link-monitor-applet/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A GNOME applet displaying the round-trip time to one or more hosts

USE_X_PREFIX=		yes
USE_GNOME=		gnomehack gnomeprefix gnomepanel
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
