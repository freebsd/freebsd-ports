# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfwinreg
PORTVERSION=	20160428
CATEGORIES=	security devel python
MASTER_SITES=	https://github.com/log2timeline/dfwinreg/releases/download/${PORTVERSION}/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Windows Registry

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	libregf>=a:devel/libregf \
		${PYTHON_PKGNAMEPREFIX}construct>=0:devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}dfdatetime>=0:security/py-dfdatetime

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py)

.include <bsd.port.mk>
