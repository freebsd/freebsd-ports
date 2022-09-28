PORTNAME=	nflistdata
DISTVERSION=	2022-03-26
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://pari.math.u-bordeaux.fr/pub/pari/packages/
PKGNAMEPREFIX=	pari-
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}/${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	List fields of small discriminant for nflist() in PARI/GP
WWW=		https://pari.math.u-bordeaux.fr/packages.html

LICENSE=	ART20

RUN_DEPENDS=	pari>0:math/pari

USES=		tar:tgz

WRKSRC=		${WRKDIR}/data/${PORTNAME}
INSTDIR=	${STAGEDIR}${PREFIX}/share/pari/${PORTNAME}

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${INSTDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
