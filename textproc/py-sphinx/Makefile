# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sphinx
PORTVERSION=	1.2.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Sphinx-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python documentation generator

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.3:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.7:${PORTSDIR}/textproc/py-docutils
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.3:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.7:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.2:${PORTSDIR}/textproc/py-pygments

USES=		python
USE_PYTHON=	autoplist distutils

post-build:
	cd ${WRKSRC}/build/lib && \
	${SETENV} PYTHONPATH=${WRKSRC}/build/lib:${PYTHONPREFIX_SITELIBDIR} \
	${PYTHON_CMD} -m sphinx.pycode.pgen2.driver -c 'import load_grammar'

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/lib/sphinx/pycode/Grammar-py${PYTHON_VER:R}-${PORTNAME}${PORTVERSION:R}.pickle \
	${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/sphinx/pycode/

	@${ECHO_CMD} ${PYTHON_SITELIBDIR:S;${PYTHONBASE}/;;}/sphinx/pycode/Grammar-py${PYTHON_VER:R}-${PORTNAME}${PORTVERSION:R}.pickle >> ${TMPPLIST}

.include <bsd.port.mk>
