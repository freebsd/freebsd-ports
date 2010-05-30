# New ports collection makefile for:    etoile-system
# Date created:         19 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	system
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

PORTSCOUT=	limit:^0\.2

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project System Tool

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/System

post-install:
	${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Etoile
	${CP} ${WRKSRC}/Services/Private/System/SystemTaskList.plist \
		${GNUSTEP_PREFIX}/System/Library/Etoile/
	${INSTALL_SCRIPT} ${WRKSRC}/setdown.sh ${WRKSRC}/setup.sh \
		${GNUSTEP_PREFIX}/System/Tools/

.include <bsd.port.mk>
