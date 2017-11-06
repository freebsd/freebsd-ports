# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cryptography
PORTVERSION=	2.0.3
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Cryptographic recipes and primitives for Python developers

LICENSE=			APACHE20 BSD3CLAUSE
LICENSE_COMB=			dual
LICENSE_FILE_APACHE20=		${WRKSRC}/LICENSE.APACHE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.BSD

BUILD_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}cffi>=1.7:devel/py-cffi
RUN_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}six>=1.4.1:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}asn1crypto>=0.21.0:devel/py-asn1crypto \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.7:devel/py-cffi \
		${PYTHON_PKGNAMEPREFIX}idna>=2.1:dns/py-idna
TEST_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}pytest>=2.9.0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}iso8601>0:devel/py-iso8601

# Python 2.7, 3.4-3.6
USES?=		python ssl
USE_PYTHON=	autoplist concurrent distutils

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddress>0:net/py-ipaddress
.endif

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cryptography/hazmat/bindings/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
