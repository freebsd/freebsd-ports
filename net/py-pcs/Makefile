# Ports collection Makefile for:   pcs
# Date created:        15 July 2006
# Whom:                gnn
#
# $FreeBSD$
#

PORTNAME=	pcs
PORTVERSION=	0.6
CATEGORIES=	net python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Beta-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Protocol Construction Set

PORTDOCS=	pcs.pdf
PORTEXAMPLES=	*

BUILD_DEPENDS=	cython>=0.11.2:${PORTSDIR}/lang/cython

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs/Web && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/scripts && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
