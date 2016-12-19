# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cryptography
PORTVERSION=	1.6
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Cryptographic recipes and primitives for Python developers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_9=	does not build (_openssl.c:75298: error: storage class specified for parameter '_cffi_type_context')

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.4.1:devel/py-cffi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4.1:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.8:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py-cffi \
		${PYTHON_PKGNAMEPREFIX}idna>=2.0:dns/py-idna
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}iso8601>0:devel/py-iso8601

USES=		python ssl
USE_PYTHON=	autoplist distutils

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddress>0:net/py-ipaddress
.endif

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cryptography/hazmat/bindings/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
