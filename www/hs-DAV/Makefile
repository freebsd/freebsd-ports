# $FreeBSD$

PORTNAME=	DAV
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command line client for RFC 4918 WebDAV protocol

LICENSE=	GPLv3

USES=		cabal

USE_CABAL=	StateVar-1.1.1.1 adjunctions-4.4_2 aeson-1.4.2.0_1 ansi-terminal-0.9 \
		ansi-wl-pprint-0.6.8.2_1 asn1-encoding-0.9.5 asn1-parse-0.9.4 \
		asn1-types-0.3.2 async-2.2.1_1 attoparsec-0.13.2.2 base-compat-0.10.5 \
		base-orphans-0.8 basement-0.0.10 bifunctors-5.5.3 \
		blaze-builder-0.4.1.0 blaze-html-0.9.1.1 blaze-markup-0.8.2.2 \
		byteable-0.1.1 cabal-doctest-1.0.6_2 call-stack-0.1.0 \
		case-insensitive-1.2.0.11 cereal-0.5.8.0 colour-2.3.4 \
		comonad-5.0.4 conduit-1.3.1 conduit-extra-1.3.0 connection-0.2.8 \
		contravariant-1.5 cookie-0.4.4 cryptonite-0.25 \
		data-default-0.7.1.1 data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 distributive-0.6 \
		dlist-0.8.0.5 exceptions-0.10.0_2 free-5.1 hashable-1.2.7.0_1 \
		hourglass-0.2.12 http-client-0.6.1 http-client-tls-0.3.5.3 \
		http-types-0.12.2 integer-logarithms-1.0.2.2 invariant-0.5.1 \
		kan-extensions-5.2 lens-4.17 memory-0.14.18 mime-types-0.1.0.9 \
		mono-traversable-1.0.11.0 network-2.7.0.2_2 network-uri-2.6.1.0_1 \
		old-locale-1.0.0.7_2 optparse-applicative-0.14.3.0 \
		parallel-3.2.2.0 pem-0.2.4 primitive-0.6.4.0_1 profunctors-5.3 \
		random-1.1_1 reflection-2.1.4 resourcet-1.2.2 scientific-0.3.6.2 \
		semigroupoids-5.3.2 semigroups-0.18.5 shakespeare-2.0.20 \
		socks-0.5.6 split-0.2.3.3_1 streaming-commons-0.2.1.0 \
		tagged-0.8.6 th-abstraction-0.2.10.0 time-locale-compat-0.1.1.5 \
		tls-1.4.1 transformers-base-0.4.5.2 transformers-compat-0.6.2 \
		typed-process-0.2.4.0 unliftio-core-0.1.2.0_1 \
		unordered-containers-0.2.10.0 utf8-string-1.0.1.1_3 \
		uuid-types-1.0.3_1 vector-0.12.0.2 vector-algorithms-0.8.0.1 \
		void-0.7.2 x509-1.7.5 x509-store-1.6.7 \
		x509-system-1.6.6 x509-validation-1.6.11 xml-conduit-1.8.0.1 \
		xml-hamlet-0.5.0 xml-types-0.3.6 zlib-0.6.2

EXECUTABLES=	hdav

CABAL_FLAGS=	network-uri

.include <bsd.port.mk>
