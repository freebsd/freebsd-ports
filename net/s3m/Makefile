PORTNAME=	s3m
DISTVERSION=	0.10.0
CATEGORIES=	net
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	nbari@tequila.io
COMMENT=	CLI for streams of data in S3 buckets
WWW=		https://s3m.stream

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	needs SSE or SSE2 type extensions to compile

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	s3m

PORTSCOUT=	limit:[0-9.]+

PLIST_FILES=	bin/s3m

do-build:
	(cd ${WRKSRC} && \
		cargo build --release)
	(cd ${WRKSRC} && \
		env HOME=${WRKDIR} cargo install --path . --force --locked)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin/
	${MV} ${WRKSRC}/target/release/s3m \
		${STAGEDIR}${PREFIX}/bin/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/s3m

.include <bsd.port.mk>
