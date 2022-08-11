PORTNAME=	cffsubr
PORTVERSION=	0.2.9.post1
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standalone CFF subroutinizer based on the AFDKO tx tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}afdko>=0:x11-fonts/py-afdko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.10.2:print/py-fonttools@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/external/

.include <bsd.port.mk>
