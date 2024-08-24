PORTNAME=	meilisearch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/meilisearch/mini-dashboard/releases/download/v${DASHBOARD_VERSION}/build.zip?dummy=/:mini_dashboard_assets \
		https://github.com/lindera-morphology/unidic-mecab/archive/refs/tags/2.1.2.tar.gz?dummy=/:lindera_unidic \
		https://github.com/lindera-morphology/mecab-ipadic/archive/refs/tags/2.7.0-20070801.tar.gz?dummy=/:mecab_ipadic \
		https://github.com/lindera-morphology/mecab-ko-dic/archive/refs/tags/2.1.1-20180720.tar.gz?dummy=/:mecab_ko_dic \
		https://milli-benchmarks.fra1.digitaloceanspaces.com/datasets/:benchmark
DISTFILES=	${MINIDASHBOARDFILE}:mini_dashboard_assets \
		mecab-ipadic-2.7.0-20070801.tar.gz:mecab_ipadic \
		unidic-mecab-2.1.2.tar.gz:lindera_unidic \
		mecab-ko-dic-2.1.1-20180720.tar.gz:mecab_ko_dic \
		smol-songs.csv.gz:benchmark \
		smol-songs-1_2.csv.gz:benchmark \
		smol-songs-3_4.csv.gz:benchmark \
		smol-songs-4_4.csv.gz:benchmark \
		smol-wiki-articles.csv.gz:benchmark \
		smol-wiki-articles-1_2.csv.gz:benchmark \
		smol-wiki-articles-3_4.csv.gz:benchmark \
		smol-wiki-articles-4_4.csv.gz:benchmark \
		movies.json.gz:benchmark \
		movies-1_2.json.gz:benchmark \
		movies-3_4.json.gz:benchmark \
		movies-4_4.json.gz:benchmark \
		nested_movies.json.gz:benchmark \
		smol-all-countries.jsonl.gz:benchmark
EXTRACT_ONLY=	${DISTFILES:N*\:benchmark:N*\:lindera_unidic:N*\:mecab_ipadic:N*\:mecab_ko_dic:C/:.*//}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Powerful, fast, and an easy to use search engine
WWW=		https://www.meilisearch.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libgit2>=0:devel/libgit2
LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libonig.so:devel/oniguruma

BROKEN_i386=	fails to build
USES=		cargo pkgconfig
USE_GITHUB=	yes

#GH_TUPLE=		meilisearch:lmdb:6a01c0a:lmdb/../lmdb-rs-501aa34a1ab7f092e3ff54a6c22ff6c55931a2d8/lmdb-sys/lmdb
DASHBOARD_VERSION=	0.2.13
MINIDASHBOARDFILE=	meilisearch-mini-dashboard-build-${DASHBOARD_VERSION}.zip
CARGO_INSTALL_PATH=	meilisearch
CARGO_ENV=		LIBGIT2_SYS_USE_PKG_CONFIG=1 \
			MILLI_BENCH_DATASETS_PATH=${WRKDIR}
PLIST_FILES=		bin/${PORTNAME}

post-extract:
.for F in ${DISTFILES:M*\:benchmark:S/:benchmark//}
	@${GUNZIP} < ${DISTDIR}/${F} >${WRKDIR}/${F:S/.gz//}
.endfor

post-patch:
	${REINPLACE_CMD} -e 's,%%MINIDASHBOARDFILE%%,${DISTDIR}/${MINIDASHBOARDFILE},'  \
		${WRKSRC}/meilisearch/build.rs
	${REINPLACE_CMD} -e 's,%%DISTDIR%%,${DISTDIR},'  \
		${CARGO_VENDOR_DIR}/lindera-unidic-0.30.0/build.rs \
		${CARGO_VENDOR_DIR}/lindera-ipadic-0.30.0/build.rs \
		${CARGO_VENDOR_DIR}/lindera-ko-dic-0.30.0/build.rs
	${GREP} -F -R -l %%WRKDIR%% ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's,%%WRKDIR%%,${WRKDIR},'

.include <bsd.port.mk>
