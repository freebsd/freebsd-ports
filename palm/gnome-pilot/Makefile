# New ports collection makefile for:	gnomepilot2
# Date created:		12 March 2003
# Whom:			Joe Marcus Clarke <marcus@marcuscom.com>
#
# $FreeBSD$
#

PORTNAME=	gnome-pilot
PORTVERSION=	2.0.17
PORTREVISION=	4
CATEGORIES=	palm comms gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	PalmPilot conduit system for GNOME 2

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2
LIB_DEPENDS=	pisock.9:${PORTSDIR}/palm/pilot-link

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier gnomepanel intlhack \
		ltverhack libgnomeui
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:22
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pisock=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gpilot-install-file.1
GCONF_SCHEMAS=	pilot.schemas

.include <bsd.port.mk>
