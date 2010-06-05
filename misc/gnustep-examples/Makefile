# New ports collection makefile for:    gnustep-examples
# Date created:         15 Mar 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnustep-examples
.if defined(WITH_GNUSTEP_DEVEL)
PORTVERSION=	1.3.0
.else
PORTVERSION=	1.2.0
PORTREVISION=	1
.endif
CATEGORIES=	misc gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep example applications

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GL=		yes

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GNUSTEP_MAKE_DIRS+=	. gui/Finger gui/GFractal gui/HostAddress gui/MyGL
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

.include <bsd.port.mk>
