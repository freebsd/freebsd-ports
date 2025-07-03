PORTNAME=	savage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	31
CATEGORIES=	math

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Primitive computer algebra system
WWW=		https://github.com/p-e-w/savage

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	p-e-w
CARGO_CARGOTOML=	${WRKSRC}/savage/Cargo.toml
CARGO_INSTALL_PATH=	./savage
CARGO_CRATES=	ahash-0.3.8 \
		aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		approx-0.5.0 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bytemuck-1.7.2 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		chumsky-0.8.0 \
		clipboard-win-4.2.2 \
		const-random-0.1.13 \
		const-random-macro-0.1.13 \
		crunchy-0.2.2 \
		darling-0.13.1 \
		darling_core-0.13.1 \
		darling_macro-0.13.1 \
		derivative-2.2.0 \
		directories-4.0.1 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.6 \
		dirs-sys-next-0.1.2 \
		endian-type-0.1.2 \
		error-code-2.3.0 \
		fd-lock-3.0.1 \
		fnv-1.0.7 \
		getrandom-0.2.3 \
		hamming-0.1.3 \
		ident_case-1.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.107 \
		log-0.4.14 \
		matrixmultiply-0.3.1 \
		memchr-2.4.1 \
		memoffset-0.6.4 \
		nalgebra-0.29.0 \
		nalgebra-macros-0.1.0 \
		nibble_vec-0.1.0 \
		nix-0.22.2 \
		num-0.4.0 \
		num-bigint-0.4.3 \
		num-complex-0.4.0 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.4.0 \
		num-traits-0.2.14 \
		paste-1.0.6 \
		permutohedron-0.2.4 \
		primal-0.3.0 \
		primal-bit-0.3.0 \
		primal-check-0.3.1 \
		primal-estimate-0.3.1 \
		primal-sieve-0.3.2 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.36 \
		quote-1.0.14 \
		radix_trie-0.2.1 \
		rawpointer-0.2.1 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rustyline-9.0.0 \
		rustyline-derive-0.6.0 \
		safe_arch-0.6.0 \
		scopeguard-1.1.0 \
		simba-0.6.0 \
		smallvec-1.7.0 \
		str-buf-1.0.5 \
		strsim-0.10.0 \
		syn-1.0.85 \
		tiny-keccak-2.0.2 \
		typenum-1.14.0 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		utf8parse-0.2.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wide-0.7.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.28.0 \
		windows_aarch64_msvc-0.28.0 \
		windows_i686_gnu-0.28.0 \
		windows_i686_msvc-0.28.0 \
		windows_x86_64_gnu-0.28.0 \
		windows_x86_64_msvc-0.28.0
PLIST_FILES=	bin/savage \
		${DOCSDIR_REL}/README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README.md ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
