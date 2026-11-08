PORTNAME=	codeaster-frontend
DISTVERSION=	2024.0	# ASTK_SERV/asrun/.__pkginfo__.py
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Aster frontend and backend asrun
WWW=		https://www.code-aster.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	${PY_SETUPTOOLS}	\
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
BUILD_RUN_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	tkpng>0:graphics/tkpng

USES=		gettext-runtime:run python shebangfix tk:run
SHEBANG_GLOB=	*.py *.sh
SHEBANG_FILES=	ASTK_SERV/share/codeaster/asrun/data/mpirun_template	\
		ASTK_SERV/bin/parallel_cp ASTK_SERV/bin/as_run		\
		ASTK_CLIENT/bin/bsf ASTK_CLIENT/bin/astk
USE_PYTHON=	pep517
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} \
		--prefix ${PREFIX} \
		${BUILD_WRKSRC}/dist/astk-${DISTVERSION}*.whl

SHEBANG_LANG=	shex
shex_OLD_CMD=	?SHELL_EXECUTION?
shex_CMD=	${LOCALBASE}/bin/bash

BINARY_ALIAS=	git=true python3=${PYTHON_CMD}

SHTAGNAME=	7d7eafcd
TAGNAME=	7d7eafcd3aa8405a8b71c9db9dc9dcbf1aee0515
TARNAME=	${PORTNAME}-${SHTAGNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${SHTAGNAME}-${TAGNAME}

PYEX2FIX=	ASTK_SERV/etc/profile.sh	\
		ASTK_SERV/bin/as_run		\
		ASTK_SERV/bin/parallel_cp

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README.md

pre-configure:
	${REINPLACE_CMD} -e 's|?HOME_PYTHON?|${PYTHONBASE}|'	\
		-e 's|?ASRUN_SITE_PKG?|${PYTHON_SITELIBDIR}|'	\
		-e 's|?WISH_EXE?|${WISH}|'	\
		${WRKSRC}/ASTK_SERV/etc/profile.sh
.for f in ${PYEX2FIX}
	${REINPLACE_CMD} -e 's|PYTHONEXECUTABLE=.*|PYTHONEXECUTABLE=${PYTHON_CMD}|' \
		${WRKSRC}/${f}
	${RM} ${WRKSRC}/${f}.bak
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PEP517_INSTALL_CMD}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
