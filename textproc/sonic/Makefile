PORTNAME=	sonic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.9
PORTREVISION=	17
CATEGORIES=	textproc
MAINTAINER=	wadegimpbc@tuta.com
COMMENT=	Fast, lightweight, and schema-less search backend
WWW=		https://github.com/valeriansaliou/sonic

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	valeriansaliou
USE_RC_SUBR=	sonic

USERS=		sonic
GROUPS=		sonic

PLIST_FILES=	bin/sonic \
		"@sample ${ETCDIR}/config.cfg.sample"
PORTDOCS=	CONFIGURATION.md PROTOCOL.md README.md
OPTIONS_DEFINE=	CHINESE DOCS JAPANESE
OPTIONS_DEFAULT=	CHINESE
CHINESE_DESC=	Chinese word segmentation
JAPANESE_DESC=	Japanese word segmentation (adds ~100MB UniDic download)

CARGO_ENV+=	DISTDIR=${DISTDIR}
CARGO_FEATURES=	--no-default-features allocator-jemalloc
CHINESE_VARS=	CARGO_FEATURES+=tokenizer-chinese
JAPANESE_VARS=	CARGO_FEATURES+=tokenizer-japanese
JAPANESE_MASTER_SITES=	https://clrd.ninjal.ac.jp/unidic_archive/cwj/2.1.2/:unidic
JAPANESE_DISTFILES=	unidic-mecab-2.1.2_src.zip:unidic

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config.cfg ${STAGEDIR}${ETCDIR}/config.cfg.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
