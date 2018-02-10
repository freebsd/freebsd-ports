# Created by: Samy Al Bahra <sbahra@kerneled.org>
# $FreeBSD$

PORTNAME=	bytestring-csv
PORTVERSION=	0.1.2
PORTREVISION=	20
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parse CSV formatted data efficiently with Haskell

LICENSE=	BSD3CLAUSE

USE_CABAL=	dlist
USE_ALEX=	yes

# Force regeneration of the lexer.
post-patch::
	@${RM} -r ${WRKSRC}/dist

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
