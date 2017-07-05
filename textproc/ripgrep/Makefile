# Created by: Petteri Valkonen <petteri.valkonen@iki.fi>
# $FreeBSD$

# vim: ts=8 noet

PORTNAME=	ripgrep
PORTVERSION=	0.5.2
CATEGORIES=	textproc

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Command line search tool

LICENSE=	MIT UNLICENSE
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_FILE_UNLICENSE=	${WRKSRC}/UNLICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	BurntSushi

PLIST_FILES=	bin/rg \
		man/man1/rg.1.gz

CARGO_CRATES=	aho-corasick-0.6.3 \
		ansi_term-0.9.0 \
		atty-0.2.2 \
		bitflags-0.8.2 \
		bytecount-0.1.6 \
		cfg-if-0.1.0 \
		clap-2.24.1 \
		crossbeam-0.2.10 \
		encoding_rs-0.5.1 \
		env_logger-0.4.2 \
		fnv-1.0.5 \
		fs2-0.4.1 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.8 \
		libc-0.2.23 \
		log-0.3.7 \
		memchr-1.0.1 \
		memmap-0.5.2 \
		num_cpus-1.4.0 \
		regex-0.2.1 \
		regex-syntax-0.4.0 \
		same-file-0.1.3 \
		simd-0.1.1 \
		strsim-0.6.0 \
		term_size-0.3.0 \
		thread-id-3.0.0 \
		thread_local-0.3.3 \
		unicode-segmentation-1.1.0 \
		unicode-width-0.1.4 \
		unreachable-0.1.1 \
		utf8-ranges-1.0.0 \
		vec_map-0.7.0 \
		void-1.0.2 \
		walkdir-1.0.7 \
		winapi-0.2.8 \
		winapi-build-0.1.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/rg.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
