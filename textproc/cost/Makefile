# New ports collection makefile for:	costsh
# Date created:				May 22, 2000
# Whom:					Allan Bowhill <kosmos@blarg.net>
#
# $FreeBSD$
#

PORTNAME=		cost
PORTVERSION=		2.2p1
CATEGORIES=		textproc tk82
MASTER_SITES=		http://www.flightlab.com/~joe/cost/

MAINTAINER=		ports@FreeBSD.org
COMMENT=	SGML/XML application programming tool

LIB_DEPENDS=		tcl82.1:${PORTSDIR}/lang/tcl82
BUILD_DEPENDS=		${NONEXISTENT}:${PORTSDIR}/lang/tcl82:patch

WRKSRC=			${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-tcl=${PREFIX}/lib/tcl8.2 \
			--with-docdir=${PREFIX}/share/doc/cost --with-charmaps
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"

do-install:
	${MKDIR} ${PREFIX}/lib/cost2.2
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/lib/*.tcl ${PREFIX}/lib/cost2.2
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/lib/*.spec ${PREFIX}/lib/cost2.2
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/lib/*.itcl ${PREFIX}/lib/cost2.2
	${INSTALL_DATA} ${WRKSRC}/libcost2.2.so ${PREFIX}/lib/cost2.2
	${INSTALL_PROGRAM} ${WRKSRC}/costsh ${PREFIX}/bin/costsh

.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Cost documentation"
	@${MKDIR} ${PREFIX}/share/doc/cost && ${CHMOD} a+rx ${PREFIX}/share/doc/cost
	@cd ${WRKDIR}/${DISTNAME}/doc && ${INSTALL_MAN} manual.html manual.ps rtflib.html simple.html \
		${PREFIX}/share/doc/cost
.endif

.include <bsd.port.mk>
