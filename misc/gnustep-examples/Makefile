# New ports collection makefile for:    gnustep-examples
# Date created:         15 Mar 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnustep-examples
PORTVERSION=	1.0.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep example applications

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
GUN_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

MAKE_APPS=	Finger GFractal GPuzzle HostAddress
INSTALL_APPS=	Finger GFractal GPuzzle HostAddress

post-build:
.for i in ${MAKE_APPS}
	@(cd ${WRKSRC}/gui/${i}; . ${SYSMAKEDIR}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
.endfor

post-install:
.for i in ${INSTALL_APPS}
	@(cd ${WRKSRC}/gui/${i}; . ${SYSMAKEDIR}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.endfor

.include <bsd.port.mk>
