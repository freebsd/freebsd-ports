# $FreeBSD$

PORTNAME=	xsv
DISTVERSION=	0.13.0
PORTREVISION=	4
CATEGORIES=	textproc
PKGNAMESUFFIX=	-rs

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fast CSV toolkit

LICENSE=	MIT UNLICENSE
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_UNLICENSE=	${WRKSRC}/UNLICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	BurntSushi

CARGO_CRATES=	aho-corasick-0.6.4 \
		bitflags-1.0.3 \
		byteorder-1.2.2 \
		cfg-if-0.1.3 \
		chan-0.1.21 \
		csv-1.0.0 \
		csv-core-0.1.4 \
		csv-index-0.1.5 \
		docopt-1.0.0 \
		filetime-0.1.15 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		lazy_static-1.0.0 \
		libc-0.2.40 \
		log-0.4.1 \
		memchr-2.0.1 \
		num-traits-0.2.4 \
		num_cpus-1.8.0 \
		proc-macro2-0.3.8 \
		quickcheck-0.6.2 \
		quote-0.5.2 \
		rand-0.3.22 \
		rand-0.4.2 \
		redox_syscall-0.1.37 \
		regex-1.0.0 \
		regex-syntax-0.6.0 \
		serde-1.0.54 \
		serde_derive-1.0.54 \
		streaming-stats-0.2.0 \
		strsim-0.7.0 \
		syn-0.13.9 \
		tabwriter-1.0.4 \
		thread_local-0.3.5 \
		threadpool-1.7.1 \
		ucd-util-0.1.1 \
		unicode-width-0.1.4 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		void-1.0.2 \
		winapi-0.3.4 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/xsv
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xsv

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
