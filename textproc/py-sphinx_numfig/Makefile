# Created by: Dru Lavigne <dru@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sphinx_numfig
PORTVERSION=	r13
CATEGORIES=	textproc
MASTER_SITES=	http://sourceforge.net/projects/numfig/files/latest/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Autonumbering figures in Sphinx

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PKGNAMEPREFIX}sphinx>=1.3.1:textproc/py-sphinx@${FLAVOR}

USES=		python:2.7 tar:tgz
USE_PYTHON=	flavors
NO_BUILD=	yes
SPHINXDIR=	${PYTHON_LIBDIR}/site-packages/sphinx
PLIST_FILES=	${SPHINXDIR}/ext/numfig.py ${SPHINXDIR}/ext/numfig.pyc

do-install:
	cd ${WRKDIR}/sphinx_numfig-r13 && \
		${MKDIR} ${STAGEDIR}${SPHINXDIR}/ext && \
		${PYTHON_CMD} setup.py install ${STAGEDIR}${SPHINXDIR} ${SPHINXDIR}/ext

.include <bsd.port.mk>
