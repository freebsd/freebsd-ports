# New ports collection makefile for:	math/p5-Graph
# Date created:				09 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Graph
PORTVERSION=	0.61
PORTEPOCH=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Graph
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Graph, the Perl module for graph operations

BUILD_DEPENDS=	${SITE_PERL}/Heap.pm:${PORTSDIR}/devel/p5-Heap \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Graph.3 \
		Graph::AdjacencyMap.3 \
		Graph::AdjacencyMap::Vertex.3 \
		Graph::AdjacencyMatrix.3 \
		Graph::BitMatrix.3 \
		Graph::Directed.3 \
		Graph::Matrix.3 \
		Graph::TransitiveClosure.3 \
		Graph::TransitiveClosure::Matrix.3 \
		Graph::Traversal.3 \
		Graph::Traversal::BFS.3 \
		Graph::Traversal::DFS.3 \
		Graph::Undirected.3 \
		Graph::UnionFind.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later version
.endif

.include <bsd.port.post.mk>
