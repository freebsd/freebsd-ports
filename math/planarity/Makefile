PORTNAME=	planarity
PORTVERSION=	3.0.2.0
DISTVERSIONPREFIX=	Version_
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Edge Addition Planarity Suite

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USE_GITHUB=	yes
GH_ACCOUNT=	graph-algorithms
GH_PROJECT=	edge-addition-planarity-suite

USES=		autoreconf libtool

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

do-test:
	(cd ${WRKSRC}/c && ${WRKSRC}/${PORTNAME} -test)

.include <bsd.port.mk>
