PORTNAME=	en-core-web-sm
DISTVERSION=	3.8.0
CATEGORIES=	textproc python
#MASTER_SITES=	https://github.com/explosion/spacy-models/releases/download/${PORTNAME}-${DISTVERSION}/ # the required wheel file has disappeared here
MASTER_SITES=	LOCAL/yuri/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	en_core_web_sm-${DISTVERSION}-py3-none-any
EXTRACT_SUFX=	.whl

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	English spaCy model for natural language processing
WWW=		https://github.com/explosion/spacy-models

LICENSE=	MIT

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}spacy>=3.8.0:textproc/py-spacy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	flavors

NO_ARCH=	yes
NO_BUILD=	yes

EXTRACT_CMD=	${UNZIP_CMD}
EXTRACT_BEFORE_ARGS=	-qo
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	cd ${WRKDIR} && ${COPYTREE_SHARE} en_core_web_sm ${STAGEDIR}${PYTHON_SITELIBDIR}
	cd ${WRKDIR} && ${COPYTREE_SHARE} "en_core_web_sm-${DISTVERSION}.dist-info" ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
