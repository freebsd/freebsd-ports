# Created by: Samy Al Bahra <sbahra@kerneled.org>
# $FreeBSD$

PORTNAME=	bytestring-csv
PORTVERSION=	0.1.2
PORTREVISION=	23
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parse CSV formatted data efficiently with Haskell

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	dlist
USE_ALEX=	yes

# Force regeneration of the lexer.
post-patch::
	@${RM} -r ${WRKSRC}/dist

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
