# New ports collection makefile for:	trac-down
# Date created:		Feb. 20, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	down
PORTVERSION=	0.0.1.r11
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracDown-${PORTVERSION:E}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A Trac plugin for listing released downloads

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		tracd:${PORTSDIR}/www/trac

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	TracDown
PYDISTUTILS_PKGVERSION=	0.0.1
PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${TRACDOWN_EGG}

TRACDOWN_EGG=	TracDown-${PORTVERSION:R}-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		TRACDOWN_EGG=${TRACDOWN_EGG} \
		TRACDOWN_EGG_VER="TracDown==${PORTVERSION:R}"

.include <bsd.port.mk>
