# New ports collection makefile for:    yodl
# Date created:         22 Oct 1997
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yodl
PORTVERSION=	2.13.2
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	An easy to use but powerful document formatting/preparation language

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		getopt:${PORTSDIR}/misc/getopt
BUILD_DEPENDS=	icmake:${PORTSDIR}/devel/icmake \
		bash:${PORTSDIR}/shells/bash \
		gsed:${PORTSDIR}/textproc/gsed

USE_PERL5_BUILD=	yes

MANCOMPRESSED=	no
MAN1=		yodl.1 yodlpost.1 yodlconverters.1 yodlverbinsert.1
MAN7=		yodlmanpage.7 yodlletter.7 yodlmacros.7 yodlbuiltins.7

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr/share/yodl"|"${PREFIX}/share/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/usr/bin"|"${PREFIX}/bin"|' \
		${WRKSRC}/src/config.h
	@${REINPLACE_CMD} -e 's|"/share/yodl"|"/share/yodl-${PORTVERSION}"| ; \
		s|"-r"|"-R"| ; \
		s|"/share/man"|"/man"| ; \
		s|"/share/doc"|"/share/doc/yodl-${PORTVERSION}"| ; \
		s|"/share/doc/yodl"|"/share/doc/yodl-${PORTVERSION}"|' \
		${WRKSRC}/build
	@${REINPLACE_CMD} -e 's|#!/usr/bin/icmake|#!${LOCALBASE}/bin/icmake|' \
		${WRKSRC}/build \
		${WRKSRC}/src/build \
		${WRKSRC}/src/yodlpost/build \
		${WRKSRC}/src/yodl/build \
		${WRKSRC}/manual/build \
		${WRKSRC}/man/build \
		${WRKSRC}/macros/build
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		s|sed |${LOCALBASE}/bin/gsed | ; \
		s|getopt |${LOCALBASE}/bin/getopt |' \
		${WRKSRC}/src/yodl/replace \
		${WRKSRC}/scripts/yodl2whatever.in \
		${WRKSRC}/scripts/configreplacements \
		${WRKSRC}/macros/rawmacros/separator \
		${WRKSRC}/macros/rawmacros/keepdiff \
		${WRKSRC}/macros/rawmacros/repairs \
		${WRKSRC}/macros/rawmacros/startdoc \
		${WRKSRC}/macros/rawmacros/makeyoin \
		${WRKSRC}/macros/rawmacros/create
	@${REINPLACE_CMD} -e 's|#!/usr/bin/perl|#!${PERL}|' \
		${WRKSRC}/macros/rawmacros/separator.pl \
		${WRKSRC}/macros/rawmacros/startdoc.pl \
		${WRKSRC}/contrib/build.pl

do-build:
	@cd ${WRKSRC} && ./build package
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ./build doc
.endif

do-install:
	@cd ${WRKSRC} && ./build install ${PREFIX}
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ./build install_doc ${PREFIX}
.endif

.include <bsd.port.mk>
