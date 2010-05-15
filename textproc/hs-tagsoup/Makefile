# New ports collection makefile for: hs-tagsoup
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tagsoup
PORTVERSION=	0.8
CATEGORIES=	textproc haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	A Haskell library for extracting information from HTML documents

CABAL_SETUP=	Setup.hs

PORTDATA=		*
INSTALL_PORTDATA=	cd ${WRKSRC} && \
			  ${INSTALL_DATA} ${WRKSRC}/tagsoup.htm ${DATADIR}

OPTIONS=	TESTPROG "Build the test program" on

.include <bsd.port.options.mk>

.if defined(WITH_TESTPROG)
CONFIGURE_ARGS+=	--flags="testprog"
EXECUTABLE+=		tagsoup
USE_HACKAGE+=		deepseq==1.1.0.0 HTTP QuickCheck>=2.1.0.0
PLIST_SUB+=		MAYBE_TESTPROG=""
.else
CONFIGURE_ARGS+=	--flags="-testprog"
PLIST_SUB+=		MAYBE_TESTPROG="@comment "
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
