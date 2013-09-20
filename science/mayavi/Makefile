# Created by: ijliao
# $FreeBSD$

PORTNAME=	mayavi
PORTVERSION=	1.5
PORTREVISION=	6
CATEGORIES=	science python
MASTER_SITES=	SF
DISTNAME=	MayaVi-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scientific data visualizer

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/vtk.pth:${PORTSDIR}/math/vtk-python \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	MayaVi
CPIO_ARGS=	--quiet -pdum -R

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.* ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${FIND} * | ${CPIO} ${CPIO_ARGS} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR})
.endif

.include <bsd.port.mk>
