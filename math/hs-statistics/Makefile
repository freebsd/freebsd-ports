# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	statistics
PORTVERSION=	0.15.0.0
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library of statistical types, data, and functions

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson>=0.6.0.0 base-orphans data-default-class dense-linear-algebra \
		erf math-functions>=0.1.5.2 math-functions monad-par>=0.3.4 \
		mwc-random>=0.13.0.0 primitive>=0.3 vector>=0.10 \
		vector-algorithms>=0.4 vector-binary-instances>=0.2.1 vector-th-unbox

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
