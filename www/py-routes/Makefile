# New ports collection makefile for:	py-routes
# Date created:		April 24 2007
# Whom:			Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	routes
PORTVERSION=	1.6.3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	source/R/Routes
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Routes-${PORTVERSION}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A Routing package for Python that matches URLs to dicts and vice versa

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYROUTES_EGG=	Routes-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYROUTES_EGG=${PYROUTES_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

.include <bsd.port.mk>
