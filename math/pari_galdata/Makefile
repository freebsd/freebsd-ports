# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	galdata
DISTVERSION=	2008-04-11
CATEGORIES=	math
MASTER_SITES=	https://pari.math.u-bordeaux.fr/pub/pari/packages/
PKGNAMEPREFIX=	pari-
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}/${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Data needed by PARI/GP for polgalois

LICENSE=	GPLv2

LIB_DEPENDS=	libpari.so:math/pari

USES=		tar:tgz

WRKSRC=		${WRKDIR}/data/${PORTNAME}
INSTDIR=	${STAGEDIR}${PREFIX}/share/pari/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${INSTDIR}/

.include <bsd.port.mk>
