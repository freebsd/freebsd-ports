PORTNAME=	keep
DISTVERSION=	2.11
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Personal shell command keeper
WWW=		https://github.com/OrkoHunter/keep

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}terminaltables3>0:textproc/py-terminaltables3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyGithub>0:devel/py-PyGithub@${PY_FLAVOR}

USES=	python
USE_PYTHON=	autoplist pep517

SUB_FILES=	pkg-message

PORTDATA=	completions/keep.zsh \
		completions/keep.bash

post-patch:
	@${REINPLACE_CMD} -e 's|%%VERSION%%|${DISTVERSION}|g' ${PATCH_WRKSRC}/keep/about.py

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/completions
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDATA} ${STAGEDIR}${DATADIR}/completions)

.include <bsd.port.mk>
