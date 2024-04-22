PORTNAME=	planarity
PORTVERSION=	3.0.2.0
DISTVERSIONPREFIX=	Version_
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Edge Addition Planarity Suite
WWW=		https://dx.doi.org/10.7155/jgaa.00091

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USE_GITHUB=	yes
GH_ACCOUNT=	graph-algorithms
GH_PROJECT=	edge-addition-planarity-suite

USES=		autoreconf libtool

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

do-test:
	(cd ${WRKSRC}/c && ${WRKSRC}/${PORTNAME} -test)

.include <bsd.port.mk>
