# Created by: tobez
# $FreeBSD$

PORTNAME=	Graph
PORTVERSION=	0.96
PORTEPOCH=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Graph, the Perl module for graph operations

BUILD_DEPENDS=	p5-Heap>=0:${PORTSDIR}/devel/p5-Heap \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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
		Graph::UnionFind.3 \
		Heap071::Elem.3 \
		Heap071::Fibonacci.3

NO_STAGE=	yes
.include <bsd.port.mk>
