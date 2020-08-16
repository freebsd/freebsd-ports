# $FreeBSD$

PORTNAME=	cputype
PORTVERSION=	0.2.1
CATEGORIES=	sysutils haskell
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Find out your CPUTYPE

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_GITLAB=     yes
GL_SITE=        https://foss.heptapod.net
GL_ACCOUNT=     bsdutils
GL_COMMIT=      0efe02ac1fa2ecbd4c881462ab64927167f9e77f

USE_CABAL=	ansi-terminal-0.10.3 \
		ansi-wl-pprint-0.6.9_1 \
		attoparsec-0.13.2.4 \
		colour-2.3.5 \
		hashable-1.3.0.0_1 \
		integer-logarithms-1.0.3_2 \
		optparse-applicative-0.15.1.0_1 \
		primitive-0.7.0.1 \
		scientific-0.3.6.2 \
		transformers-compat-0.6.5

.include <bsd.port.mk>
