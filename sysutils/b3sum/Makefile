PORTNAME=	b3sum
DISTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	Command line implementation of the BLAKE3 hash function

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	blake3-team
GH_PROJECT=	BLAKE3

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

WRKSRC_SUBDIR=	${PORTNAME}

CARGO_CRATES=	anyhow-1.0.53 \
		arrayref-0.3.6 \
		arrayvec-0.7.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		block-buffer-0.10.0 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		clap-3.0.12 \
		constant_time_eq-0.1.5 \
		crossbeam-channel-0.5.2 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.6 \
		crossbeam-utils-0.8.6 \
		crypto-common-0.1.1 \
		digest-0.10.1 \
		duct-0.13.5 \
		either-1.6.1 \
		fastrand-1.7.0 \
		generic-array-0.14.5 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		indexmap-1.8.0 \
		instant-0.1.12 \
		lazy_static-1.4.0 \
		libc-0.2.114 \
		memchr-2.4.1 \
		memmap-0.7.0 \
		memoffset-0.6.5 \
		num_cpus-1.13.1 \
		once_cell-1.9.0 \
		os_pipe-0.9.2 \
		os_str_bytes-6.0.0 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.10 \
		remove_dir_all-0.5.3 \
		scopeguard-1.1.0 \
		shared_child-0.3.5 \
		strsim-0.10.0 \
		subtle-2.4.1 \
		tempfile-3.3.0 \
		termcolor-1.1.2 \
		textwrap-0.14.2 \
		typenum-1.15.0 \
		version_check-0.9.4 \
		wild-2.0.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PORTDOCS=	*.md
PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/.. && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
