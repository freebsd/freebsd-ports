# New ports collection makefile for:	costsh
# Date created:				May 22, 2000
# Whom:					Allan Bowhill <kosmos@blarg.net>
#
# $FreeBSD$
#

PORTNAME=	cost
PORTVERSION=	2.2p1
PORTREVISION=	2
CATEGORIES=	textproc tcl
MASTER_SITES=	http://www.flightlab.com/~joe/cost/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGML/XML application programming tool

USE_TCL=	84
USE_TCL_BUILD=	84
WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-docdir=${PREFIX}/share/doc/cost --with-charmaps
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC" TCL_INCLUDE_SPEC="${LOCALBASE}/include/tcl8.4"

post-patch:
	@${REINPLACE_CMD} -e 's|TCL_SRC_DIR%g|TCL_INCLUDE_SPEC%g|' \
		${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's|-I$$(TCL_SRC_DIR)/generic|$$(TCL_SRC_DIR)|' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${PREFIX}/lib/cost2.2
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/lib/*.tcl ${PREFIX}/lib/cost2.2
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/lib/*.spec ${PREFIX}/lib/cost2.2
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/lib/*.itcl ${PREFIX}/lib/cost2.2
	${INSTALL_DATA} ${WRKSRC}/libcost2.2.so ${PREFIX}/lib/cost2.2
	${INSTALL_PROGRAM} ${WRKSRC}/costsh ${PREFIX}/bin/costsh

.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Cost documentation"
	@${MKDIR} ${DOCSDIR} && ${CHMOD} a+rx ${DOCSDIR}
	@cd ${WRKDIR}/${DISTNAME}/doc && \
		${INSTALL_MAN} manual.html manual.ps rtflib.html simple.html \
		${DOCSDIR}/
.endif

.include <bsd.port.mk>
