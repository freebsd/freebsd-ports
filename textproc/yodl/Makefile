# New ports collection makefile for:    yodl
# Date created:         22 Oct 1997
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yodl
PORTVERSION=	2.15.1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
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
MAN1=		yodl.1 yodlpost.1 yodlconverters.1 yodlverbinsert.1 yodlstriproff.1
MAN7=		yodlbuiltins.7 yodlmanpage.7 yodlletter.7 yodlmacros.7

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr"|"${PREFIX}"| ; \
		s|"/share/yodl"|"/share/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/man"|"/man"| ; \
		s|"/share/doc/yodl"|"/share/doc/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/doc/yodl-doc"|"/share/doc/${PORTNAME}-${PORTVERSION}/doc"| ; \
		s|"gcc"|"${CC}"|' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} -e 's|yodlconverters.1|yodlconverters.1.gz| ; \
		s|".1"|".1.gz"|' \
		${WRKSRC}/icmake/install
	@${REINPLACE_CMD} -e 's|#!/usr/bin/icmake|#!${LOCALBASE}/bin/icmake| ; \
		s|"-O2 -Wall"|"-Wall ${CFLAGS}"|' \
		${WRKSRC}/build
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		s|sed |${LOCALBASE}/bin/gsed | ; \
		s|getopt |${LOCALBASE}/bin/getopt |' \
		${WRKSRC}/src/yodl/replace \
		${WRKSRC}/scripts/yodl2whatever.in \
		${WRKSRC}/scripts/configreplacements \
		${WRKSRC}/scripts/createmacros \
		${WRKSRC}/scripts/hrefnotmpinstall \
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
	@${REINPLACE_CMD} -e 's|../../yodl/|../../../${PORTNAME}-${PORTVERSION}/|' \
		${WRKSRC}/manual/yo/manual.yo

do-build:
	@cd ${WRKSRC} && ./build programs
.if !defined(NO_INSTALL_MANPAGES)
	@cd ${WRKSRC} && ./build man
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ./build manual
.endif

do-install:
	@cd ${WRKSRC} && ./build install programs ""
	@cd ${WRKSRC} && ./build install macros ""
.if !defined(NO_INSTALL_MANPAGES)
	@cd ${WRKSRC} && ./build install man ""
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ./build install manual "" && ./build install docs ""
.endif

.include <bsd.port.mk>
