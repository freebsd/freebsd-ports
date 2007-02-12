# New ports collection makefile for:	py-flup
# Date created:		2006-12-16
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	flup
PORTVERSION=	0.5.r2307
CATEGORIES=	www python
MASTER_SITES=	http://www.saddi.com/software/flup/dist/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flup-${PORTVERSION:E}

MAINTAINER=	lwhsu@lwhsu.org
COMMENT=	Random assortment of WSGI servers, middleware

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

PYFLUP_EGG=	${PORTNAME}-${PORTVERSION:R}-py${PYTHON_VERSION:S/^python//}.egg

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="${PORTNAME}==${PORTVERSION:R}"

PLIST_SUB=	PYFLUP_EGG=${PYFLUP_EGG}

.include <bsd.port.mk>
