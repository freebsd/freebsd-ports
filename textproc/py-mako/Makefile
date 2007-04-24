# New ports collection makefile for:	py-mako
# Date created:		April 23 2007
# Whom:			Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	mako
PORTVERSION=	0.1.5
CATEGORIES=	textproc www python
MASTER_SITES=	http://www.makotemplates.org/downloads/ \
		${MASTER_SITE_CHEESESHOP} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	source/M/Mako
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mako-${PORTVERSION}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Super-fast templating language in Python

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}myghtyutils>=0.52:${PORTSDIR}/devel/py-myghtyutils
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYMAKO_EGG=	Mako-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYMAKO_EGG=${PYMAKO_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

.include <bsd.port.mk>
