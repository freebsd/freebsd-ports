# New ports collection makefile for:	dvipdfm
# Date created:		16 January 2000
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=		dvipdfm
PORTVERSION=		0.13.2c
CATEGORIES=		print
MASTER_SITES=		http://gaspra.kettering.edu/dvipdfm/

MAINTAINER=		stephen@math.missouri.edu

BUILD_DEPENDS=		${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX
LIB_DEPENDS=		png:${PORTSDIR}/graphics/png
RUN_DEPENDS=		kpsewhich:${PORTSDIR}/print/teTeX

WRKSRC=			${WRKDIR}/dvipdfm

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS="${CXXFLAGS} -I${PREFIX}/include" \
			CFLAGS="${CFLAGS} -I${PREFIX}/include" \
			LDFLAGS=-L${PREFIX}/lib
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

MAN1=			dvipdfm.1

post-install:
	strip ${PREFIX}/bin/dvipdfm
	strip ${PREFIX}/bin/ebb
	mktexlsr
	${MKDIR} ${PREFIX}/share/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/latex-support/dvipdfm.def ${PREFIX}/share/dvipdfm
#	${INSTALL_DATA} ${WRKSRC}/latex-support/hdvipdfm.def ${PREFIX}/share/dvipdfm
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/dvipdfm.tex ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/mwicks.bb ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/mwicks.jpeg ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/transistor.bb ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/transistor.eps ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/transistor.fig ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/transistor.pdf ${PREFIX}/share/texmf/doc/dvipdfm
	( cd ${PREFIX}/share/texmf/doc/dvipdfm ; tex dvipdfm ; ${PREFIX}/bin/dvipdfm dvipdfm ; ${RM} dvipdfm.log dvipdfm.dvi )
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
