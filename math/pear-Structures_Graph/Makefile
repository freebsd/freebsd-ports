# Ports collection makefile for:  pear-Structures_Graph
# Date created:			  09 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Structures_Graph
PORTVERSION=	1.0.1
CATEGORIES=	math devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR graph datastructure manipulation library

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Structures
FILES=		Graph/Manipulator/TopologicalSorter.php \
		Graph/Manipulator/AcyclicTest.php Graph/Node.php Graph.php
DOCS=		Structures_Graph.pkg
_DOCSDIR=	docs/tutorials/Structures_Graph

post-extract:
	@${MV} ${WRKSRC}/Structures/* ${WRKSRC}/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
