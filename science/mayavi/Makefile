# ex:ts=8
# Ports collection makefile for:	mayavi
# Date created:			Mar 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mayavi
PORTVERSION=	1.4
CATEGORIES=	science python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	MayaVi-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scientific data visualizer

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/vtk.pth:${PORTSDIR}/math/vtk-python \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
