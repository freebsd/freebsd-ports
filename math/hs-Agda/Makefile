PORTNAME=	Agda
DISTVERSION=	2.8.0
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant
WWW=		https://wiki.portal.chalmers.se/agda/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compiler goes out of memory

BUILD_DEPENDS=	emacs:editors/emacs@nox

USES=		cabal

USE_LOCALE=	en_US.UTF-8

USE_CABAL=	ListLike-4.7.8.3 \
		OneTuple-0.4.2_1 \
		QuickCheck-2.16.0.0 \
		STMonadTrans-0.4.8_1 \
		StateVar-1.2.2 \
		aeson-2.2.3.0_4 \
		alex-3.5.3.0 \
		ansi-terminal-1.1.3 \
		ansi-terminal-types-1.1.3 \
		ap-normalize-0.1.0.1 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		base-compat-0.14.1 \
		base-orphans-0.9.3 \
		bifunctors-5.6.2_2 \
		blaze-builder-0.4.3 \
		blaze-html-0.9.2.0_1 \
		blaze-markup-0.8.3.0_2 \
		boxes-0.1.5 \
		case-insensitive-1.2.1.0 \
		character-ps-0.1 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		contravariant-1.5.5 \
		data-default-0.8.0.1 \
		data-fix-0.3.4_1 \
		data-hash-0.2.0.1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		edit-distance-0.2.2.1_1 \
		enummapset-0.7.3.0 \
		equivalence-0.4.1 \
		filelock-0.1.1.7 \
		filemanip-0.3.6.3_1 \
		fmlist-0.9.4 \
		generic-data-1.1.0.2 \
		generic-deriving-1.14.6_1 \
		generically-0.1.1_4 \
		gitrev-1.3.1 \
		happy-2.1.6 \
		happy-lib-2.1.6 \
		hashable-1.5.0.0_1 \
		hsc2hs-0.68.10_4 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		invariant-0.6.4_1 \
		monad-control-1.0.3.1 \
		murmur-hash-0.1.0.11 \
		network-uri-2.6.4.2_1 \
		nonempty-containers-0.3.5.0 \
		nonempty-vector-0.2.4 \
		optparse-applicative-0.19.0.0 \
		os-string-2.0.7_1 \
		parallel-3.2.2.0_9 \
		peano-0.1.0.2 \
		pqueue-1.5.0.0_3 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		process-extras-0.7.4_1 \
		profunctors-5.6.3 \
		random-1.3.1 \
		regex-base-0.94.0.3 \
		regex-tdfa-1.3.2.4 \
		scientific-0.3.8.0_2 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_2 \
		show-combinators-0.2.0.0_2 \
		split-0.2.5 \
		splitmix-0.1.3.1 \
		strict-0.5.1_1 \
		tagged-0.8.9 \
		tasty-1.5.3_2 \
		text-iso8601-0.1.1_2 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0_1 \
		th-compat-0.1.6 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		unix-compat-0.7.4 \
		unordered-containers-0.2.20_4 \
		uri-encode-1.5.0.7_3 \
		utf8-string-1.0.2 \
		uuid-types-1.0.6_3 \
		vector-0.13.2.0_1 \
		vector-hashtables-0.1.2.1 \
		vector-stream-0.1.0.1_3 \
		witherable-0.5_1 \
		zlib-0.7.1.0_2

CABAL_EXECUTABLES=	agda agda-mode
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}
agda_DATADIR_VARS=	Agda
agda-mode_DATADIR_VARS=	Agda

PLIST_SUB=	AGDA_VER=${PORTVERSION}

post-install:
	${SETENV} Agda_datadir=${WRKSRC}/src/data ${STAGEDIR}${PREFIX}/libexec/cabal/agda-mode compile
	${FIND} ${WRKSRC}/src/data/lib/prim/Agda -name '*.agda' -exec ${SETENV} Agda_datadir=${WRKSRC}/src/data ${STAGEDIR}${PREFIX}/libexec/cabal/agda {} \;
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/prim/Agda
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} emacs-mode ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
