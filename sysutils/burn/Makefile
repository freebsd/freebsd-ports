# New ports collection makefile for:    burn
# Date created:         21 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	burn
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gsburn

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep based CD burning program

LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
RUN_DEPENDS+=	cdrecord:${PORTSDIR}/sysutils/cdrtools
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao

WRKSRC=		${WRKDIR}/Burn
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_BUNDLES+=	Cddb:${CDDB_BUNDLE_PORT}
USE_GNUSTEP_LOCAL_BUNDLES+=	AudioCD:${CDPLAYER_PORT}
USE_GNUSTEP_SYSTEM_LIBS+=	PrefsModule:${PREFERENCES_PORT}
USE_GNUSTEP_SYSTEM_LIBS+=	Inspector:${GWORKSPACE_PORT}
MAKEFILE=	GNUmakefile

CDDB_BUNDLE_PORT?=	audio/cddb-bundle
CDPLAYER_PORT?=		sysutils/gnustep-cdplayer
PREFERENCES_PORT?=	deskutils/preferences.app
GWORKSPACE_PORT?=	deskutils/gworkspace

.include <bsd.port.mk>
