# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	http-server
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for writing Haskell web servers

LICENSE=	BSD

USE_CABAL=	HTTP>=4000.2.0 mime>=0.3 network>=2 url>=2 utf8-string>=0.3.4

INSTALL_PORTEXAMPLES=	cd ${WRKSRC}/example && \
			  ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MEXAMPLES}
SUB_FILES=	pkg-message

post-install::
	@${CAT} ${PKGMESSAGE}
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
