PORTNAME=	keep
PORTVERSION=	2.10.1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Personal shell command keeper
WWW=		https://github.com/OrkoHunter/keep

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}terminaltables>0:textproc/py-terminaltables@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyGithub>0:devel/py-PyGithub@${PY_FLAVOR}

USES=	python
USE_PYTHON=	autoplist distutils

SUB_FILES=	pkg-message

PORTDATA=	completions/keep.zsh \
		completions/keep.bash

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/completions
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDATA} ${STAGEDIR}${DATADIR}/completions)

.include <bsd.port.mk>
