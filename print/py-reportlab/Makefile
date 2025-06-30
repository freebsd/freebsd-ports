PORTNAME=	reportlab
DISTVERSION=	4.4.2
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PFBFER}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library to create PDF documents using the Python language
WWW=		https://www.reportlab.com/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_PILLOW}

USES=		cpe python
USE_PYTHON=	autoplist pep517

PFBFER_VERSION=	20180109
PFBFER=		pfbfer-${PFBFER_VERSION}.zip

MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
NO_ARCH=	yes

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
PORTDOCS=	reportlab-userguide.pdf

OPTIONS_DEFINE=	CJK FREETYPE DOCS
OPTIONS_DEFAULT=CJK FREETYPE

CJK_DESC=	Adobe CMaps

CJK_RUN_DEPENDS=	${LOCALBASE}/share/fonts/adobe-cmaps/ac15/cid2code.txt:print/adobe-cmaps
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTDIR%%|${DISTDIR}|' \
			  -e 's|%%PFBFER%%|${PFBFER}|' \
				${WRKSRC}/setup.py

post-patch-DOCS-on:
.for f in genAll.py userguide/genuserguide.py
	@${REINPLACE_CMD} -e 's|%%STAGEDIR%%|${STAGEDIR}|' \
			  -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|' \
				${WRKSRC}/docs/${f}
.endfor

post-install-DOCS-on:
	@cd ${WRKSRC}/docs && ${PYTHON_CMD} genAll.py
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

do-test:
	@(cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ./runAll.py)

.include <bsd.port.mk>
