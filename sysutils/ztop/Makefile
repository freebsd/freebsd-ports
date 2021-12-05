PORTNAME=	ztop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Display ZFS dataset I/O in real time

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	asomers
CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		byteorder-1.4.3 \
		cassowary-0.3.0 \
		cc-1.0.69 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		humanize-rs-0.1.5 \
		ieee754-0.2.6 \
		lazy_static-1.4.0 \
		libc-0.2.98 \
		memchr-2.4.0 \
		memoffset-0.6.4 \
		nix-0.22.0 \
		numtoa-0.1.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		redox_syscall-0.2.9 \
		redox_termios-0.1.2 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		same-file-1.0.6 \
		strsim-0.8.0 \
		structopt-0.3.22 \
		structopt-derive-0.4.15 \
		syn-1.0.74 \
		sysctl-0.4.2 \
		termion-1.5.6 \
		textwrap-0.11.0 \
		thiserror-1.0.26 \
		thiserror-impl-1.0.26 \
		tui-0.15.0 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
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
