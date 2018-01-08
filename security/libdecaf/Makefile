# $FreeBSD$

PORTNAME=	libdecaf
PORTVERSION=	0.9.4
CATEGORIES=	security
MASTER_SITES=	SF/ed448goldilocks/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Implementation of elliptic curve cryptography

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake python:2.7 tar:tgz
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/ristretto bin/shakesum \
		lib/libdecaf.so lib/libdecaf.so.1

post-patch:
	@${REINPLACE_CMD} -e 's|PYTHON ?= python|PYTHON ?= ${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/* ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/build/lib/* ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
