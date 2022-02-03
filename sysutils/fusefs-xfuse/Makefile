PORTNAME=	xfuse
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0-alpha
PORTREVISION=	6
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	mail@KhaledEmara.dev
COMMENT=	Read-only FUSE server implementing XFS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo fuse

USE_GITHUB=	yes
GH_ACCOUNT=	KhaledEmaraDev
GH_TAGNAME=	9c8824

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		byteorder-1.4.3 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		crc-2.0.0 \
		crc-catalog-1.1.1 \
		fuse-0.3.1 \
		hermit-abi-0.1.18 \
		libc-0.2.97 \
		log-0.3.9 \
		log-0.4.14 \
		num-derive-0.3.3 \
		num-traits-0.2.14 \
		pkg-config-0.3.19 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		strsim-0.8.0 \
		syn-1.0.73 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thread-scoped-1.0.2 \
		time-0.1.44 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		uuid-0.8.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/xfs-fuse \
		man/man1/xfs-fuse.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xfs-fuse
	${INSTALL_MAN} ${WRKSRC}/doc/xfs-fuse.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
