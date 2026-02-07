PORTNAME=	oama
DISTVERSION=	0.18
CATEGORIES=	mail
PKGNAMEPREFIX=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	OAuth credential Manager
WWW=		https://github.com/pdobsan/oama

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	ghc-9.6.7:lang/ghc96
LIB_DEPENDS=	libsecret-1.so:security/libsecret
RUN_DEPENDS=	gpgme-config:security/gpgme

USES=		cabal gnome
USE_GITHUB=	yes
GH_ACCOUNT=	pdobsan
USE_GNOME=	introspection
USE_CABAL=	HUnit-1.6.2.0 \
		OneTuple-0.4.2_1 \
		QuickCheck-2.15.0.1_1 \
		StateVar-1.2.2 \
		aeson-2.2.3.0_3 \
		ansi-terminal-1.1.2 \
		ansi-terminal-types-1.1 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		attoparsec-0.14.4_6 \
		attoparsec-aeson-2.2.2.0 \
		auto-update-0.2.6 \
		base-orphans-0.9.3 \
		base16-bytestring-1.0.2.0_1 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		bifunctors-5.6.2_2 \
		bitvec-1.1.5.0_3 \
		blaze-builder-0.4.2.3 \
		bsb-http-chunked-0.0.0.4_4 \
		byteorder-1.0.4 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cborg-0.2.10.0_2 \
		cereal-0.5.8.3 \
		character-ps-0.1 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		conduit-1.3.6.1 \
		conduit-extra-1.3.7 \
		contravariant-1.5.5 \
		cookie-0.5.0 \
		crypton-1.0.2 \
		crypton-connection-0.4.3 \
		crypton-x509-1.7.7 \
		crypton-x509-store-1.6.10 \
		crypton-x509-system-1.6.7 \
		crypton-x509-validation-1.6.14 \
		data-default-0.8.0.1 \
		data-default-class-0.2.0.0 \
		data-fix-0.3.4_1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		easy-file-0.2.5 \
		either-5.0.2_2 \
		fast-logger-3.2.5 \
		generically-0.1.1_4 \
		half-0.3.2 \
		hashable-1.5.0.0_1 \
		hourglass-0.2.12_1 \
		hsc2hs-0.68.10_4 \
		hsyslog-5.0.2_1 \
		http-client-0.7.18 \
		http-client-tls-0.3.6.4 \
		http-conduit-2.3.9.1 \
		http-date-0.0.11 \
		http-semantics-0.3.0 \
		http-types-0.12.4 \
		http2-5.3.9 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		iproute-1.7.15 \
		libyaml-0.1.4 \
		libyaml-clib-0.2.5 \
		memory-0.18.0_1 \
		mime-types-0.1.2.0 \
		mono-traversable-1.0.21.0 \
		network-3.2.7.0 \
		network-byte-order-0.1.7 \
		network-control-0.1.4 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.4 \
		optparse-applicative-0.18.1.0_1 \
		os-string-2.0.7 \
		pem-0.2.4 \
		pretty-simple-4.1.3.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.0.0_2 \
		profunctors-5.6.2_3 \
		psqueues-0.2.8.1 \
		random-1.2.1.3 \
		recv-0.1.0 \
		resourcet-1.3.0 \
		scientific-0.3.8.0_2 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_2 \
		serialise-0.2.6.1_4 \
		simple-sendfile-0.2.32 \
		socks-0.6.1 \
		split-0.2.5 \
		splitmix-0.1.1 \
		streaming-commons-0.2.3.0 \
		strict-0.5.1_1 \
		string-qq-0.0.6 \
		strings-1.1_1 \
		tagged-0.8.9 \
		tasty-1.5.3_1 \
		text-iso8601-0.1.1_2 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0_1 \
		th-compat-0.1.6 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		time-manager-0.2.2 \
		tls-2.1.8 \
		transformers-compat-0.7.2 \
		twain-2.2.0.1 \
		typed-process-0.2.12.0 \
		unix-compat-0.7.3_1 \
		unix-time-0.4.16 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20_4 \
		utf8-string-1.0.2 \
		uuid-types-1.0.6_2 \
		vault-0.3.1.5_10 \
		vector-0.13.2.0_1 \
		vector-algorithms-0.9.1.0 \
		vector-stream-0.1.0.1_3 \
		wai-3.2.4 \
		wai-extra-3.1.17 \
		wai-logger-2.5.0 \
		warp-3.4.7 \
		witherable-0.5_1 \
		word8-0.1.3 \
		yaml-0.11.11.2_2 \
		zlib-0.7.1.0_2
CABAL_PROJECT=	append

PLIST_FILES=	share/bash-completion/completions/oama \
		share/fish/vendor_completions.d/oama.fish \
		share/zsh/site-functions/_oama

post-extract:
	(cd ${WRKSRC}/completions && \
	${REINPLACE_CMD} \
		-e 's,/usr/bin,${PREFIX}/bin,g' \
		oama.bash oama.fish oama.zsh)

post-install:
	(cd ${WRKSRC}/completions && \
	${INSTALL_DATA} oama.bash ${STAGEDIR}${PREFIX}/share/bash-completion/completions/oama && \
	${INSTALL_DATA} oama.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/oama.fish && \
	${INSTALL_DATA} oama.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_oama)

.include <bsd.port.mk>
