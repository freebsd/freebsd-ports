# ex:ts=8
# Ports collection makefile for:	mayavi
# Date created:			Mar 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mayavi
PORTVERSION=	1.1
CATEGORIES=	science python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	MayaVi-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_MESA=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=lib/${PYTHON_VERSION}/site-packages

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
