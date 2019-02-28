# $FreeBSD$

PORTNAME=	sd
DISTVERSIONPREFIX=	sd-
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Intuitive find and replace tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	chmln

CARGO_CRATES=	aho-corasick-0.6.9 \
		ansi_term-0.11.0 \
		arrayvec-0.4.10 \
		atomicwrites-0.2.2 \
		atty-0.2.11 \
		bitflags-1.0.4 \
		cc-1.0.28 \
		cfg-if-0.1.6 \
		clap-2.32.0 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		either-1.5.0 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		heck-0.3.1 \
		lazy_static-1.2.0 \
		libc-0.2.49 \
		memchr-2.1.2 \
		memoffset-0.2.1 \
		nix-0.11.0 \
		nodrop-0.1.13 \
		num_cpus-1.9.0 \
		proc-macro2-0.4.24 \
		quote-0.6.10 \
		rand-0.4.5 \
		rand_core-0.3.0 \
		rayon-1.0.3 \
		rayon-core-1.4.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.44 \
		redox_termios-0.1.1 \
		regex-1.1.0 \
		regex-syntax-0.6.5 \
		remove_dir_all-0.5.1 \
		scopeguard-0.3.3 \
		strsim-0.7.0 \
		structopt-0.2.14 \
		structopt-derive-0.2.14 \
		syn-0.15.23 \
		tempdir-0.3.7 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unescape-0.1.0 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		void-1.0.2 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/sd
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sd

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
