# New ports collection makefile for:    proj4
# Date created:         28 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	proj4
PORTVERSION=	0.3
CATEGORIES=	misc
MASTER_SITES=	http://www.gnustep.it/enrico/position/
DISTNAME=	position-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Cartographic projection software

WRKSRC=		${WRKDIR}/Position/PROJ.4
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
BUILD_WRKSRC=	${WRKSRC}/src

MAN1=		geod.1 nad2nad.1 proj.1
MAN3=		pj_init.3

post-configure:
	${REINPLACE_CMD} -e 's|make|gmake|' ${WRKSRC}/install

do-install:
	cd ${WRKSRC} && ${SH} install

.include <bsd.port.mk>
