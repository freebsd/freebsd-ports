# New ports collection makefile for:	py-flup
# Date created:		2006-12-16
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	flup
PORTVERSION=	0.5.r2311
CATEGORIES=	www python
MASTER_SITES=	http://www.saddi.com/software/flup/dist/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flup-${PORTVERSION:E}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Random assortment of WSGI servers, middleware

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDES}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYFLUP_EGG}

PYFLUP_EGG=	${PORTNAME}-${PORTVERSION:R}-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYFLUP_EGG=${PYFLUP_EGG} \
		PYFLUP_EGG_VER="${PORTNAME}==${PORTVERSION:R}"

.include <bsd.port.mk>
