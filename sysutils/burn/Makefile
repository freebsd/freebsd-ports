# New ports collection makefile for:    burn
# Date created:         21 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	burn
PORTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	sysutils gnustep
MASTER_SITES=	SF/gs${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep based CD burning program

LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao

USE_CDRTOOLS=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_BUNDLES+=	Cddb:${CDDB_BUNDLE_PORT}
USE_GNUSTEP_LOCAL_BUNDLES+=	AudioCD:${CDPLAYER_PORT}
USE_GNUSTEP_SYSTEM_LIBS+=	PrefsModule:${PREFERENCES_PORT}
USE_GNUSTEP_SYSTEM_LIBS+=	Inspector:${GWORKSPACE_PORT}

WRKSRC=		${WRKDIR}/Burn
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}
HEADERS=	Burn/ExternalTools.h Burn/PreferencesModule.h \
		Constants.h Functions.h Track.h

CDDB_BUNDLE_PORT?=	audio/cddb-bundle
CDPLAYER_PORT?=		audio/gnustep-cdplayer
PREFERENCES_PORT?=	deskutils/preferences.app
GWORKSPACE_PORT?=	deskutils/gworkspace

post-install:
	${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/Headers/Burn
.for i in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${i} \
		${GNUSTEP_PREFIX}/Local/Library/Headers/Burn/
.endfor

.include <bsd.port.mk>
