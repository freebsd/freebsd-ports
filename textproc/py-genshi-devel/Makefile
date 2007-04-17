# New ports collection makefile for:	py-genshi
# Date created:		2007-01-23
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	Genshi
PORTVERSION=	0.4
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	textproc www python
MASTER_SITES=	http://ftp.edgewall.com/pub/${PORTNAME:L}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME:L}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python toolkit for stream-based generation of output for the web

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYGENSHI_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYGENSHI_EGG=${PYGENSHI_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

.include <bsd.port.mk>
