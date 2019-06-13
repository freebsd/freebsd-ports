# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	Agda
PORTVERSION=	2.6.0.1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant

BUILD_DEPENDS=	alex:devel/hs-alex \
		happy:devel/hs-happy

USES=		cabal

USE_LOCALE=	en_US.UTF-8
USE_CABAL=	EdisonAPI-1.3.1 EdisonCore-1.3.2.1 QuickCheck-2.13.1 \
		STMonadTrans-0.4.3 aeson-1.4.3.0 alex-3.2.4 async-2.2.1_1 \
		attoparsec-0.13.2.2_2 base-compat-0.10.5 blaze-builder-0.4.1.0 \
		blaze-html-0.9.1.1 blaze-markup-0.8.2.2 boxes-0.1.5 \
		data-hash-0.2.0.1 dlist-0.8.0.6 edit-distance-0.2.2.1_1 \
		equivalence-0.3.4 exceptions-0.10.2 fail-4.9.0.0 \
		geniplate-mirror-0.7.6_1 gitrev-1.3.1 happy-1.19.9_3 hashable-1.2.7.0_1 \
		hashtables-1.2.3.2 ieee754-0.8.0 integer-logarithms-1.0.3 \
		murmur-hash-0.1.0.9 network-uri-2.6.1.0 primitive-0.6.4.0_1 \
		random-1.1_1 regex-base-0.93.2 regex-tdfa-1.2.3.2 \
		scientific-0.3.6.2 split-0.2.3.3_1 splitmix-0.0.2 strict-0.3.2 \
		tagged-0.8.6 th-abstraction-0.3.1.0 time-locale-compat-0.1.1.5 \
		transformers-compat-0.6.5 unordered-containers-0.2.10.0 \
		uri-encode-1.5.0.5 utf8-string-1.0.1.1_3 uuid-types-1.0.3_1 \
		vector-0.12.0.3 zlib-0.6.2

EXECUTABLES=		agda-mode agda
agda_DATADIR_VARS=	Agda

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/prim/Agda
	find ${WRKSRC}/src/data/lib/prim/Agda -name '*.agda' -exec ${SETENV} ${PORTNAME}_datadir=${WRKSRC}/src/data ${STAGEDIR}${PREFIX}/libexec/cabal/agda {} \;
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
