# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	nftables
DISTVERSION=	2008-09-29
CATEGORIES=	math
MASTER_SITES=	https://pari.math.u-bordeaux.fr/pub/pari/packages/
PKGNAMEPREFIX=	pari-
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}/${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Repackaging of the historical megrez number field tables for PARI/GP

LICENSE=	GPLv2

LIB_DEPENDS=	libpari.so:math/pari

USES=		tar:tgz

INSTDIR=	${STAGEDIR}${PREFIX}/share/pari/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/T* ${INSTDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
