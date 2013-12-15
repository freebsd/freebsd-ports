# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sphinx
PORTVERSION=	1.2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Sphinx-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python documentation generator

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.3:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.7:${PORTSDIR}/textproc/py-docutils
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.3:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.7:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.2:${PORTSDIR}/textproc/py-pygments

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	Sphinx

post-build:
	cd ${WRKSRC} && \
	${SETENV} PYTHONPATH=${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}:${PYTHONPREFIX_SITELIBDIR} \
	${PYTHON_CMD} -m sphinx.pycode.pgen2.driver -c 'import load_grammar'

post-install:
	${INSTALL_DATA} ${WRKSRC}/sphinx/pycode/Grammar${PYTHON_VER}.pickle \
	${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/sphinx/pycode/

	${ECHO_CMD} ${PYTHON_SITELIBDIR:S;${PYTHONBASE}/;;}/${PYEASYINSTALL_EGG}/sphinx/pycode/Grammar${PYTHON_VER}.pickle >> ${TMPPLIST}

.include <bsd.port.mk>
