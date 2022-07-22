PORTNAME=	ab-av1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AV1 re-encoding using ffmpeg, svt-av1 & vmaf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		SvtAv1EncApp:multimedia/svt-av1

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	alexheretic
PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

CARGO_CRATES=	anyhow-1.0.58 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bytes-1.2.0 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		clap-3.2.14 \
		clap_complete-3.2.3 \
		clap_derive-3.2.7 \
		clap_lex-0.2.4 \
		console-0.15.0 \
		encode_unicode-0.3.6 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		ffprobe-0.3.2 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		getrandom-0.2.7 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		indexmap-1.9.1 \
		indicatif-0.16.2 \
		itoa-1.0.2 \
		lazy_static-1.4.0 \
		libc-0.2.126 \
		log-0.4.17 \
		memchr-2.5.0 \
		mio-0.8.4 \
		num_cpus-1.13.1 \
		num_threads-0.1.6 \
		number_prefix-0.4.0 \
		once_cell-1.13.0 \
		os_str_bytes-6.2.0 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		ppv-lite86-0.2.16 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.40 \
		quote-1.0.20 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		ryu-1.0.10 \
		serde-1.0.140 \
		serde_derive-1.0.140 \
		serde_json-1.0.82 \
		shell-escape-0.1.5 \
		signal-hook-registry-1.4.0 \
		slab-0.4.7 \
		strsim-0.10.0 \
		syn-1.0.98 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		textwrap-0.15.0 \
		time-0.3.11 \
		time-macros-0.2.4 \
		tokio-1.20.0 \
		tokio-macros-1.8.0 \
		tokio-process-stream-0.3.0 \
		tokio-stream-0.1.9 \
		tokio-util-0.7.3 \
		unicode-ident-1.0.2 \
		unicode-width-0.1.9 \
		unix-named-pipe-0.2.0 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1

post-install:
.for _shell in bash fish zsh
	@${ECHO_MSG} "Generating ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}"
	@${CARGO_CARGO_RUN} run ${CARGO_BUILD_ARGS} -- print-completions ${_shell} \
		>${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}
.endfor

.include <bsd.port.mk>
