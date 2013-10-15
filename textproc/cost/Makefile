# Created by: Allan Bowhill <kosmos@blarg.net>
# $FreeBSD$

PORTNAME=	cost
DISTVERSION=	2.3-2004-10-08
CATEGORIES=	textproc tcl
MASTER_SITES=	http://www.flightlab.com/~joe/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGML/XML application programming tool

OPTIONS_DEFINE=	DOCS

USES+=		tk
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=-prefix=${PREFIX} \
		--exec-prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tcl-include=${TCL_INCLUDEDIR} \
		--with-docdir=${DOCSDIR}
CFLAGS+=	-fPIC

PORTDOCS=	*
WRKSRC=		${WRKDIR}/${PORTNAME}-2.3/src

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|$$(TCL_PKGPATH)|${PREFIX}/lib|' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|wish8.0|${WISH}|' ${WRKSRC}/../demos/sgmlbrowse.tcl

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/../demos/sgmlbrowse.tcl ${STAGEDIR}${PREFIX}/bin/sgmlbrowse
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
