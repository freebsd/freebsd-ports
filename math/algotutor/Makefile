# New ports collection makefile for:	algotutor
# Date created:        19 January 2005
# Whom:                Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	algotutor
PORTVERSION=	0.7
CATEGORIES=	math
MASTER_SITES=	http://www.ofset.org/~ckhung/dl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	An interactive tutorial for algorithms and data structures

BROKEN=		Unfetchable

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5_BUILD=yes
NO_BUILD=	yes

MAN1=		algotutor.1 gen_at_graph.1
BINFILES=	algotutor gen_at_graph
LIBFILES=	.algotutor BST.pm DCEdge.pm Edge.pm Graph.pm Heap.pm \
		PQueue.pm RBTree.pm RecCanvas.pm RecDialog.pm TreeNode.pm \
		Vector.pm Vertex.pm utilalgo

post-patch:
	${PERL} -pi -e "s'!!PREFIX!!'${PREFIX}'g" ${WRKSRC}/algotutor

do-install:
	${MKDIR} ${PREFIX}/share/algotutor
	${CP} -R ${WRKSRC}/data ${PREFIX}/share/algotutor
	${CP} -R ${WRKSRC}/graph ${PREFIX}/share/algotutor
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${file} ${PREFIX}/man/man1
.endfor
	${MKDIR} ${SITE_PERL}/algotutor
.for file in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin/
.endfor
.for file in ${LIBFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${SITE_PERL}/algotutor/
.endfor

.include <bsd.port.mk>
