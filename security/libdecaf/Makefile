# $FreeBSD$

PORTNAME=	libdecaf
PORTVERSION=	1.0.0
CATEGORIES=	security
MASTER_SITES=	SF/ed448goldilocks/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Implementation of elliptic curve cryptography

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64

USES=		gmake python:2.7 tar:tgz
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|PYTHON ?= python|PYTHON ?= ${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/* ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/src/GENERATED/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/build/lib/* ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
