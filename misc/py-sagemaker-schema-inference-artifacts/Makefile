PORTNAME=	sagemaker-schema-inference-artifacts
DISTVERSION=	0.0.5
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI}
MASTER_SITE_SUBDIR=	51/b3/b39099f265041678c03798c636d8460f8cc6a398deb299b05441f1aaa812
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sagemaker_schema_inference_artifacts-${DISTVERSION}-py3-none-any
EXTRACT_SUFX=	.whl # PYPI only contains the wheel file and no sources can be found, seo we use the wheel as source in this special case

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SageMaker: Library for Hugging Face Task Sample Inputs and Outputs
WWW=		https://sagemaker.readthedocs.io/en/stable/ \
		https://github.com/aws/

LICENSE=	APACHE20

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}json5>0:devel/py-json5@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist flavors

NO_ARCH=	yes

EXTRACT_CMD=	${UNZIP_CMD}
EXTRACT_BEFORE_ARGS=	-qo
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}
WRKSRC=		${WRKDIR}

PEP517_BUILD_DEPEND=	# wheel-only, no build from source
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

do-build:
	@${DO_NADA}

.include <bsd.port.mk>
