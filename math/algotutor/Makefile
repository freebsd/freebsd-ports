# $FreeBSD$

PORTNAME=	algotutor
PORTVERSION=	0.8.6
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	http://www.cyut.edu.tw/~ckhung/dl/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Interactive tutorial for algorithms and data structures

BUILD_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	build
NO_BUILD=	yes
NO_ARCH=	yes

MANPAGES=	algotutor.1 gen_at_graph.1
BINFILES=	algotutor gen_at_graph
LIBFILES=	BST.pm Board.pm Collection.pm Configurable.pm DCEdge.pm \
		Edge.pm Graph.pm Heap.pm Line.pm PQueue.pm RBTree.pm \
		RecCanvas.pm RecDialog.pm TreeNode.pm Vector.pm Vector2.pm \
		Vector3.pm Vertex.pm basic.pl utilalgo

USES=		shebangfix perl5 tar:tgz
SHEBANG_FILES=	algotutor dp/flwa dp/lcs dp/matrixchain \
		gen_at_graph graph/flwa

post-patch:
	@${REINPLACE_CMD} -e 's,!!SITE_PERL!!,${PREFIX}/${SITE_PERL_REL},' \
		-e 's|!!PREFIX!!|${PREFIX}|g' \
			${WRKSRC}/algotutor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/algotutor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/algotutor
	${CP} -R ${WRKSRC}/data ${STAGEDIR}${PREFIX}/share/algotutor
	${CP} -R ${WRKSRC}/cgeom ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/algotutor
	${CP} -R ${WRKSRC}/dp ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/algotutor
	${CP} -R ${WRKSRC}/graph ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/algotutor
.for file in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/doc/${file} ${STAGEDIR}${PREFIX}/man/man1
.endfor
.for file in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
.for file in ${LIBFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/algotutor
.endfor

.include <bsd.port.mk>
