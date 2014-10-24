# Created by: gnn
# $FreeBSD$

PORTNAME=	pcs
PORTVERSION=	0.6
CATEGORIES=	net python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Beta-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Protocol Construction Set

LICENSE=	BSD3CLAUSE

PORTDOCS=	pcs.pdf
PORTEXAMPLES=	*

BUILD_DEPENDS=	cython>=0.11.2:${PORTSDIR}/lang/cython

USES=		python
USE_PYTHON=	distutils pythonprefix

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/Web && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/scripts && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
