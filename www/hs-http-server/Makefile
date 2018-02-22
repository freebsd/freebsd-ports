# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	http-server
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for writing Haskell web servers

LICENSE=	BSD3CLAUSE

USE_CABAL=	HTTP>=4000.2.0 mime>=0.3 network>=2.6 network-uri>=2.6 \
		text>=1.0 url>=2.0 utf8-string>=0.3.4

INSTALL_PORTEXAMPLES=	cd ${WRKSRC}/example && \
			  ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

OPTIONS_DEFINE=		EXAMPLES

FLAGS_ENABLE=	network-uri

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MEXAMPLES}
SUB_FILES=	pkg-message

post-install::
	@${CAT} ${PKGMESSAGE}
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
