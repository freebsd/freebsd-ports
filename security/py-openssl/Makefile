# Created by: ijliao
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	0.14
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyOpenSSL-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python interface to the OpenSSL library

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0.2.1:${PORTSDIR}/security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:${PORTSDIR}/devel/py-six

OPTIONS_DEFINE=	EXAMPLES

USES=		cpe python
USE_PYTHON=	distutils autoplist pythonprefix

CPE_VENDOR=	jean-paul_calderone
CPE_PRODUCT=	py${PORTNAME}

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

regression-test: build
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test)

.include <bsd.port.mk>
