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

PORTCOMMENT=	The MayaVi Data Visualizer

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_MESA=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=lib/${PYTHON_VERSION}/site-packages

.include <bsd.port.mk>
