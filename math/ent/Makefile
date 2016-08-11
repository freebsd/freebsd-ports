# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	ent
PORTVERSION=	0.20080128
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.fourmilab.ch/random/
DISTNAME=	random
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Entropy calculation and analysis of putative random sequences

USES=		compiler zip
NO_WRKSUBDIR=	yes
ALL_TARGET=	ent
PLIST_FILES=	bin/ent
TEST_TARGET=	check

PORTDOCS=	ent.html entitle.gif

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|^CFLAGS |&+|' ${WRKSRC}/Makefile
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|-g ||' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
