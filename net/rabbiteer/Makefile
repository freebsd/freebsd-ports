# $FreeBSD$

PORTNAME=	rabbiteer
DISTVERSION=	1.4.1
PORTREVISION=	17
CATEGORIES=	net

MAINTAINER=	dch@FreeBSD.org
COMMENT=	AMQP & RabbitMQ command-line tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE-MIT

USES=		cargo
USE_GITHUB=	yes

GH_ACCOUNT=	algesten
GH_PROJECT=	${PORTNAME}-rs
GH_TAGNAME=	c881238

CARGO_CRATES=	aho-corasick-0.5.3 \
		amq-proto-0.1.0 \
		amqp-0.1.1 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		backtrace-0.3.9 \
		backtrace-sys-0.1.24 \
		bit-vec-0.4.4 \
		bitflags-1.0.4 \
		byteorder-0.5.3 \
		cc-1.0.24 \
		cfg-if-0.1.5 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		conduit-mime-types-0.7.3 \
		enum_primitive-0.1.1 \
		env_logger-0.3.5 \
		error-chain-0.10.0 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		idna-0.1.5 \
		kernel32-sys-0.2.2 \
		libc-0.2.49 \
		log-0.3.9 \
		log-0.4.5 \
		matches-0.1.8 \
		memchr-0.1.11 \
		num-traits-0.1.43 \
		num-traits-0.2.5 \
		percent-encoding-1.0.1 \
		rand-0.5.5 \
		rand_core-0.2.1 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-0.1.80 \
		regex-syntax-0.3.9 \
		rustc-demangle-0.1.9 \
		rustc-serialize-0.3.24 \
		strsim-0.7.0 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread-id-2.0.0 \
		thread_local-0.2.7 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-width-0.1.5 \
		url-1.7.1 \
		utf8-ranges-0.1.3 \
		vec_map-0.8.1 \
		winapi-0.2.8 \
		winapi-0.3.5 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/rabbiteer

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rabbiteer

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} README.md ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
