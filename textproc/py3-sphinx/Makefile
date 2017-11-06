# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../py-sphinx

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.3:devel/py3-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.11:textproc/py3-docutils \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py3-six
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py3-babel\
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.3:devel/py3-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.11:textproc/py3-docutils \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py3-pygments \
		${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py3-babel \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=0.1:textproc/py3-sphinx_rtd_theme \
		${PYTHON_PKGNAMEPREFIX}alabaster>=0.7:textproc/py3-alabaster \
		${PYTHON_PKGNAMEPREFIX}snowballstemmer>=1.1:textproc/py3-snowballstemmer \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py3-six \
		${PYTHON_PKGNAMEPREFIX}imagesize>=0.7.1:graphics/py3-imagesize \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=	python:3.3+

.include "${MASTERDIR}/Makefile"
