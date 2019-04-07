# Created by: ijliao
# $FreeBSD$

PORTNAME=	goblin
DISTVERSION=	2.8b30
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}2/${PORTNAME}2/${PORTNAME}.${DISTVERSION}
DISTNAME=	${PORTNAME}.${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graph Object Library for Network Programming Problems

LICENSE=	LGPL21 GPLv2+ # GPLv2 for (optional) bundled glpk
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/tcl/LGPL

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2019-05-08
CONFLICTS=	glpk-[0-9]*

USES=		gmake tk tar:tgz
USE_LDCONFIG=	yes
MAKE_ARGS=	CC="${CC}" CCFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		LD="${CXX}" LIBS="${LIBS}" \
		libtcl=${TCL_SHLIB_VER} libtk=${TK_SHLIB_VER} \
		prefix=${PREFIX}
ALL_TARGET=	all shared
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include/tcl${TCL_VER} -I${LOCALBASE}/include/ \
		-I${LOCALBASE}/include/tk${TK_VER} -fPIC
CXXFLAGS+=	-fPIC
LIBS+=		-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER} -ltk${TK_SHLIB_VER} -lm -pthread

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${WISH}|g' ${WRKSRC}/display
	@${REINPLACE_CMD} -e \
		's|%%WISH%%|${WISH}|g; \
		s|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/Makefile.conf
	@${REINPLACE_CMD} -e 's|\./gosh|${PREFIX}/bin/gosh|; \
		s|\[pwd\] tcl|${PREFIX}/lib/goblin|g' \
		${WRKSRC}/goblet
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gosh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/goblet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/display ${STAGEDIR}${PREFIX}/bin/goblin-display
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	(cd ${WRKSRC}/include && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/${PORTNAME})
	${INSTALL} -d ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/tcl && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/lib/libgoblin.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libgoblin.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libglpk.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libglpk.so ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html)
	(cd ${WRKSRC}/doku && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
