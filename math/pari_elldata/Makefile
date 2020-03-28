# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	elldata
DISTVERSION=	2019-09-12
CATEGORIES=	math
MASTER_SITES=	https://pari.math.u-bordeaux.fr/pub/pari/packages/
PKGNAMEPREFIX=	pari-
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}/${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Elliptic Curve Data for PARI/GP

LICENSE=	ART20

LIB_DEPENDS=	libpari.so:math/pari

USES=		tar:tgz

WRKSRC=		${WRKDIR}/data/${PORTNAME}
INSTDIR=	${STAGEDIR}${PREFIX}/share/pari/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/ell* ${INSTDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
