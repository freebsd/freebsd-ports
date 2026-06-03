PORTNAME=	pymupdf
PORTVERSION=	1.27.2.2
CATEGORIES=	print python
MASTER_SITES=	PYPI \
		https://mupdf.com/downloads/archive/:mupdf
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mupdf-1.27.2-source.tar.gz:mupdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python bindings for the PDF toolkit and renderer MuPDF
WWW=		https://github.com/pymupdf/PyMuPDF

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	fails to build

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		bash:shells/bash \
		swig:devel/swig \
		${PYTHON_PKGNAMEPREFIX}clang>0:devel/py-clang@${PY_FLAVOR} \
		${LOCALBASE}/llvm16/lib/libclang.so.16:devel/llvm16

USES=		gmake gettext-runtime python
USE_PYTHON=	autoplist concurrent pep517 pytest # 35 tests fail, see https://github.com/pymupdf/PyMuPDF/issues/4960

MAKE_ENV+=	MUPDF_MAKE=gmake \
		CLANG_LIBRARY_FILE=${LOCALBASE}/llvm16/lib/libclang.so.16
TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PATH=${STAGEDIR}${PREFIX}/bin:"${PATH}"

post-extract:
	${CP} ${DISTDIR}/mupdf-1.27.2-source.tar.gz ${WRKSRC}/
	cd ${WRKSRC} && ${TAR} xzf mupdf-1.27.2-source.tar.gz

.include <bsd.port.mk>
