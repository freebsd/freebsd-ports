PORTNAME=	diskus
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	32
CATEGORIES=	sysutils

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	Mminimal, fast alternative to 'du -sh'
WWW=		https://github.com/sharkdp/diskus/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	ansi_term-0.11.0 \
		arrayvec-0.4.12 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.5 \
		either-1.6.1 \
		fuchsia-cprng-0.1.1 \
		hermit-abi-0.1.19 \
		humansize-1.1.1 \
		itoa-0.4.8 \
		lazy_static-1.4.0 \
		libc-0.2.107 \
		memoffset-0.6.4 \
		nodrop-0.1.14 \
		num-format-0.4.0 \
		num_cpus-1.13.0 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		rdrand-0.4.0 \
		remove_dir_all-0.5.3 \
		scopeguard-1.1.0 \
		strsim-0.8.0 \
		tempdir-0.3.7 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		unicode-width-0.1.9 \
		vec_map-0.8.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/diskus \
		share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	*.md
OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
