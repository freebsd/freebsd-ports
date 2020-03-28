# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	galpol
DISTVERSION=	2018-06-25
CATEGORIES=	math
MASTER_SITES=	https://pari.math.u-bordeaux.fr/pub/pari/packages/
PKGNAMEPREFIX=	pari-
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}/${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Database of Galois polynomials for PARI/GP

LICENSE=	GPLv2

LIB_DEPENDS=	libpari.so:math/pari

USES=		tar:tgz

WRKSRC=		${WRKDIR}/data/${PORTNAME}
INSTDIR=	${STAGEDIR}${PREFIX}/share/pari/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${INSTDIR}
	(cd ${WRKSRC} && ${FIND} . | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${INSTDIR}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
