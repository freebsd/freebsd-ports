# New ports collection makefile for:	py-beaker
# Date created:		Jun 16 2007
# Whom:			Dryice Liu <dryice@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beaker
PORTVERSION=	0.7.4
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	source/B/Beaker
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Beaker-${PORTVERSION}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A Session and Caching library with WSGI Middleware

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYBEAKER_EGG=	Beaker-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYBEAKER_EGG=${PYBEAKER_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

.include <bsd.port.mk>
