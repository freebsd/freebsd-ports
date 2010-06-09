# ex:ts=8
# Ports collection makefile for:	goblin
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	goblin
DISTVERSION=	2.8b30
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}2/${PORTNAME}2/${PORTNAME}.${DISTVERSION}
DISTNAME=	${PORTNAME}.${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Graph Object Library for Network Programming Problems

USE_TK=		84
USE_TCL=	84
USE_XORG=	x11
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	CC="${CC}" CCFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		LD="${CXX}" LIBS="-lm ${LDFLAGS}" LISShared="-lm ${LDFLAGS}" \
		libtcl=84 libtk=84 prefix=${PREFIX}
ALL_TARGET=	all shared
PLIST_SUB+=	VERSION=${PORTVERSION:R}

CFLAGS+=	-I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include/ \
		-I${LOCALBASE}/include/tk8.4 ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -ltcl84 -ltk84 ${PTHREAD_LIBS}

WISH=		${LOCALBASE}/bin/wish8.4

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		does not build on !i386
.endif

post-patch:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin/wish|${WISH}|g' ${WRKSRC}/display
	${REINPLACE_CMD} -e 's|%%WISH%%|${WISH}|g;s|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/Makefile.conf
	${REINPLACE_CMD} -e 's|\./gosh|${PREFIX}/bin/gosh|; \
	    s|\[pwd\] tcl|${PREFIX}/lib/goblin|g' \
	    ${WRKSRC}/goblet
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gosh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/goblet ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/display ${PREFIX}/bin/goblin-display
	${INSTALL} -d ${PREFIX}/include/${PORTNAME}
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} \*.h ${PREFIX}/include/${PORTNAME})
	${INSTALL} -d ${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/tcl && ${COPYTREE_SHARE} \* ${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/lib/libglpk.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libgoblin.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libglpk.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libgoblin.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL} -d ${DOCSDIR}/html
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} \* ${DOCSDIR}/html)
	(cd ${WRKSRC}/doku && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
