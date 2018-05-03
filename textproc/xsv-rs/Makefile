# $FreeBSD$

PORTNAME=	xsv
DISTVERSION=	0.12.2
PORTREVISION=	1
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

CARGO_CRATES=	aho-corasick-0.6.3 \
		byteorder-1.0.0 \
		chan-0.1.19 \
		csv-1.0.0-beta.4 \
		csv-core-0.1.3 \
		csv-index-0.1.3 \
		docopt-0.7.0 \
		filetime-0.1.10 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.8 \
		libc-0.2.40 \
		log-0.3.8 \
		memchr-1.0.1 \
		num-0.1.37 \
		num-bigint-0.1.37 \
		num-complex-0.1.37 \
		num-integer-0.1.34 \
		num-iter-0.1.33 \
		num-rational-0.1.36 \
		num-traits-0.1.37 \
		num_cpus-1.4.0 \
		quickcheck-0.4.1 \
		quote-0.3.15 \
		rand-0.3.15 \
		regex-0.2.2 \
		regex-syntax-0.4.1 \
		rustc-serialize-0.3.24 \
		serde-1.0.8 \
		serde_derive-1.0.8 \
		serde_derive_internals-0.15.1 \
		streaming-stats-0.1.28 \
		strsim-0.6.0 \
		syn-0.11.11 \
		synom-0.11.3 \
		tabwriter-1.0.3 \
		thread-id-3.1.0 \
		thread_local-0.3.3 \
		threadpool-1.3.2 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		unreachable-0.1.1 \
		utf8-ranges-1.0.0 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-build-0.1.1

PLIST_FILES=	bin/xsv
PORTDOCS=	README.md

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xsv
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
