# ex:ts=8
# Ports collection makefile for:	mayavi
# Date created:			Mar 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mayavi
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	SF
DISTNAME=	MayaVi-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scientific data visualizer

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/vtk.pth:${PORTSDIR}/math/vtk-python \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	MayaVi
CPIO_ARGS=	--quiet -pdum -R

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${FIND} * | ${CPIO} ${CPIO_ARGS} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR})
.endif

.include <bsd.port.mk>
