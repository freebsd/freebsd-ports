# ex:ts=8
# New ports collection makefile for:	domc
# Date created:			Oct 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	domc
PORTVERSION=	0.5.1
CATEGORIES=	devel
MASTER_SITES=	http://auditorymodels.org/domc/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	expat.1:${PORTSDIR}/textproc/expat

SHLIB_MAJOR=	0

MAKE_ENV=	SHLIB_MAJOR="${SHLIB_MAJOR}"
INSTALLS_SHLIB=	yes
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/dom.h ${PREFIX}/include
	${CAT} ${WRKSRC}/include/stack.h >> ${PREFIX}/include/dom.h
	${INSTALL_DATA} ${WRKSRC}/libdomc.so.${SHLIB_MAJOR} ${PREFIX}/lib
	${LN} -sf libdomc.so.${SHLIB_MAJOR} ${PREFIX}/lib/libdomc.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
