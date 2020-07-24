# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	psutil
PORTVERSION=	5.7.2
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Process utilities module for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PY_ENUM34} \
		${PY_IPADDRESS}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}psutil121

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unittest2>=0:devel/py-unittest2@${PY_FLAVOR}
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psutil/_psutil_bsd.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psutil/_psutil_posix.so

.include <bsd.port.post.mk>
