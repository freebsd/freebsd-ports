# New ports collection makefile for:	math/p5-Graph
# Date created:				09 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Graph
PORTVERSION=	0.20101
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Graph
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Heap.pm:${PORTSDIR}/devel/p5-Heap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Graph.3 \
		Graph::BFS.3 \
		Graph::Base.3 \
		Graph::DFS.3 \
		Graph::Directed.3 \
		Graph::HeapElem.3 \
		Graph::Traversal.3 \
		Graph::Undirected.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
