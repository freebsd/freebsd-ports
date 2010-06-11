# New ports collection makefile for:    stepulator.app
# Date created:         30 Aug 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	stepulator
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	math gnustep
MASTER_SITES=	http://www.linuks.mine.nu/stepulator/ \
		${MASTER_SITE_GNUSTEP_CH}
DISTNAME=	${PORTNAME}-gs-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Scientific calculator implementing RPN notation for GNUstep

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Stepulator-gs

post-extract:
	${LN} ${WRKSRC}/LICENSE ${WRKSRC}/COPYRIGHT

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE \
		${GNUSTEP_LOCAL_APPS}/Stepulator.app/Resources/

.include <bsd.port.mk>
