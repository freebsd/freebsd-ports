PORTNAME=	cffsubr
PORTVERSION=	0.2.9.post1
PORTREVISION=	1
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standalone CFF subroutinizer based on the AFDKO tx tool
WWW=		https://github.com/adobe-type-tools/cffsubr

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	tx:x11-fonts/afdko \
		${PYTHON_PKGNAMEPREFIX}afdko>=0:x11-fonts/py-afdko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.10.2:print/py-fonttools@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
PLIST_FILES=	${PYTHON_SITELIBDIR}/cffsubr/tx

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/external/

post-install:
	${LN} -s ${LOCALBASE}/bin/tx ${STAGEDIR}${PYTHON_SITELIBDIR}/cffsubr/tx

.include <bsd.port.mk>
