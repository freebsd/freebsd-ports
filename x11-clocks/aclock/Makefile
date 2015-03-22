# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	aclock
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	x11-clocks gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	AClock-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analog Clock for GNUstep

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/AClock.app/AClock

.include <bsd.port.mk>
