# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net lang
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-${LIBPROXY_SLAVE}

COMMENT=	Python binding for libproxy

USES=		python
USE_PYTHON=	flavors py3kplist

LIBPROXY_SLAVE=	python
MASTERDIR=	${.CURDIR}/../libproxy

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
