# New ports collection makefile for:	py-genshi
# Date created:		2007-01-23
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	Genshi
PORTVERSION=	0.3.6
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	textproc www python
MASTER_SITES=	http://ftp.edgewall.com/pub/${PORTNAME:L}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME:L}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python toolkit for stream-based generation of output for the web

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR:S|${PREFIX}/||}/${PYGENSHI_EGG}
PYGENSHI_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

SUB_FILES=	pkg-deinstall pkg-install
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG_VER="${PORTNAME}==${PORTVERSION}"

.include <bsd.port.mk>
