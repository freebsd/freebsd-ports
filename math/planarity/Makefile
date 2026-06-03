PORTNAME=	planarity
PORTVERSION=	4.0.1.0
DISTVERSIONPREFIX=	Version_
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Edge Addition Planarity Suite
WWW=		https://dx.doi.org/10.7155/jgaa.00091

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USE_GITHUB=	yes
GH_ACCOUNT=	graph-algorithms
GH_PROJECT=	edge-addition-planarity-suite

USES=		autoreconf libtool pkgconfig

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
	${REINPLACE_CMD} -e 's|@docdir@/samples|${EXAMPLESDIR}|'	\
		${WRKSRC}/c/samples/Makefile.am

do-test:
	(cd ${WRKSRC} && ${WRKSRC}/test-samples.sh)

.include <bsd.port.mk>
