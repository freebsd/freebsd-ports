# New ports collection makefile for:	gnomepilot2
# Date created:		12 March 2003
# Whom:			Joe Marcus Clarke <marcus@marcuscom.com>
#
# $FreeBSD$
#

PORTNAME=	gnomepilot2
PORTVERSION=	2.0.11
CATEGORIES=	palm comms gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-pilot/2.0
DISTNAME=	gnome-pilot-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	3Com PalmPilot conduit system for GNOME 2

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2
LIB_DEPENDS=	pisock.8:${PORTSDIR}/palm/pilot-link

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier gnomepanel intlhack
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-pisock=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gpilot-install-file.1

.include <bsd.port.mk>
