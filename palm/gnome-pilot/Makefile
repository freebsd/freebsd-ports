# Created by: Joe Marcus Clarke <marcus@marcuscom.com>
# $FreeBSD$

PORTNAME=	gnome-pilot
PORTVERSION=	2.0.17
PORTREVISION=	6
CATEGORIES=	palm comms gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	PalmPilot conduit system for GNOME 2

DEPRECATED=	gnome-panel 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2
LIB_DEPENDS=	pisock.9:${PORTSDIR}/palm/pilot-link

USES=		gmake iconv pathfix pkgconfig gettext
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehier gnomepanel intlhack \
		ltverhack libgnomeui
USE_AUTOTOOLS=	libtool
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pisock=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

MAN1=		gpilot-install-file.1
GCONF_SCHEMAS=	pilot.schemas

NO_STAGE=	yes
.include <bsd.port.mk>
