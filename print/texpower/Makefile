# ex:ts=8
# Ports collection makefile for:	texpower
# Date created:			Dec 30, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	texpower
PORTVERSION=	0.1.0b
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	latex-
DISTNAME=	${PORTNAME}-0-1b

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Creating dynamic online presentations with LaTeX

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} \
		MKTEXLSR=${MKTEXLSR}
ALL_TARGET=	unpack

TEXMFLOCAL=	share/texmf-local
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
DOCFILES=	00readme.txt 01install.txt manual.pdf

do-build:
	@(cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${BUILD_WRKSRC}/tpslifonts && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${MKDIR} ${PREFIX}/${TEXMFLOCAL}/tex/latex/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.sty *.cls *.cfg \
		${PREFIX}/${TEXMFLOCAL}/tex/latex/${PORTNAME}
	${MKDIR} ${PREFIX}/${TEXMFLOCAL}/tex/latex/${PORTNAME}/tpslifonts
	cd ${WRKSRC}/tpslifonts && ${INSTALL_DATA} *.sty  \
		${PREFIX}/${TEXMFLOCAL}/tex/latex/${PORTNAME}/tpslifonts
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
