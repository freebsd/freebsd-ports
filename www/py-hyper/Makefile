# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hyper
PORTVERSION=	0.5.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	HTTP/2 Client for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} == 3300 || (${PYTHON_VER} == 2.7 && ${PYTHON_REL} < 2709)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openssl>=0.14:security/py-openssl \
		${PYTHON_PGNAMEPREFIX}service_identity>=14.0.0:security/py-service_identity
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/test/certs/
	@${CP} ${FILESDIR}/files-server.py ${WRKSRC}/test/server.py
	@${CP} ${FILESDIR}/files-server.key ${WRKSRC}/test/certs/server.key
	@${CP} ${FILESDIR}/files-server.crt ${WRKSRC}/test/certs/server.crt

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test --pytest-args "-k 'not test_integration'"

.include <bsd.port.post.mk>
