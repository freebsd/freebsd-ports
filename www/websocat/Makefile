# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	websocat
DISTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	WebSockets tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	vi

CARGO_FEATURES=	ssl seqpacket

CARGO_CRATES=	atty-0.2.11 \
		base64-0.5.2 \
		base64-0.6.0 \
		bitflags-0.9.1 \
		bitflags-1.0.4 \
		byteorder-1.2.6 \
		bytes-0.4.9 \
		cc-1.0.22 \
		cfg-if-0.1.5 \
		clap-2.32.0 \
		core-foundation-0.2.3 \
		core-foundation-sys-0.2.3 \
		derivative-1.0.0 \
		either-1.5.0 \
		env_logger-0.5.13 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.17 \
		httparse-1.3.2 \
		humantime-1.1.1 \
		hyper-0.10.13 \
		idna-0.1.5 \
		iovec-0.1.2 \
		itertools-0.5.10 \
		kernel32-sys-0.2.2 \
		language-tags-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.1.0 \
		lazycell-0.6.0 \
		libc-0.2.43 \
		log-0.3.9 \
		log-0.4.4 \
		matches-0.1.8 \
		mime-0.2.6 \
		mio-0.6.15 \
		mio-named-pipes-0.1.6 \
		mio-uds-0.6.6 \
		miow-0.2.1 \
		miow-0.3.3 \
		native-tls-0.1.5 \
		net2-0.2.33 \
		num_cpus-1.8.0 \
		openssl-0.9.24 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.35 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.13 \
		proc-macro2-0.4.13 \
		quick-error-1.2.2 \
		quote-0.3.15 \
		quote-0.6.8 \
		rand-0.3.22 \
		rand-0.4.3 \
		readwrite-0.1.1 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		remove_dir_all-0.5.1 \
		safemem-0.2.0 \
		schannel-0.1.13 \
		scoped-tls-0.1.2 \
		security-framework-0.1.16 \
		security-framework-sys-0.1.16 \
		sha1-0.2.0 \
		slab-0.3.0 \
		slab-0.4.1 \
		slab_typesafe-0.1.2 \
		smart-default-0.2.0 \
		socket2-0.3.7 \
		structopt-0.2.10 \
		structopt-derive-0.2.10 \
		syn-0.10.8 \
		syn-0.11.11 \
		syn-0.14.9 \
		synom-0.11.3 \
		tempdir-0.3.7 \
		termcolor-1.0.2 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		time-0.1.40 \
		tokio-core-0.1.12 \
		tokio-file-unix-0.4.2 \
		tokio-io-0.1.5 \
		tokio-process-0.1.6 \
		tokio-signal-0.1.5 \
		tokio-stdin-stdout-0.1.4 \
		tokio-timer-0.1.2 \
		tokio-tls-0.1.4 \
		tokio-uds-0.1.5 \
		traitobject-0.1.0 \
		typeable-0.1.2 \
		unicase-1.4.2 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-width-0.1.5 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		url-1.7.1 \
		vcpkg-0.2.6 \
		version_check-0.1.4 \
		websocket-0.20.3 \
		winapi-0.2.8 \
		winapi-0.3.5 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1 \
		ws2_32-sys-0.2.1

PLIST_FILES=	bin/websocat

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/websocat

.include <bsd.port.mk>
