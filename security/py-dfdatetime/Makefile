# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfdatetime
PORTVERSION=	20200613
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
#		https://github.com/log2timeline/dfdatetime/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Date and Time

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} "s,share/doc/dfdatetime,${DOCSDIR_REL}," ${WRKSRC}/setup.py

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py)

.include <bsd.port.mk>
