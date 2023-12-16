PORTNAME=	ztop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	12
CATEGORIES=	sysutils

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Display ZFS dataset I/O in real time
WWW=		https://github.com/asomers/ztop

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	asomers
CARGO_CRATES=	aho-corasick-0.7.18 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		byteorder-1.4.3 \
		cassowary-0.3.0 \
		cfg-if-1.0.0 \
		clap-3.2.22 \
		clap_derive-3.2.18 \
		clap_lex-0.2.4 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		humanize-rs-0.1.5 \
		indexmap-1.9.1 \
		libc-0.2.124 \
		memchr-2.4.1 \
		nix-0.24.0 \
		numtoa-0.1.0 \
		once_cell-1.15.0 \
		os_str_bytes-6.3.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		quote-1.0.15 \
		redox_syscall-0.2.11 \
		redox_termios-0.1.2 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		same-file-1.0.6 \
		strsim-0.10.0 \
		syn-1.0.89 \
		sysctl-0.4.4 \
		termcolor-1.1.3 \
		termion-1.5.6 \
		textwrap-0.15.1 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		tui-0.15.0 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
