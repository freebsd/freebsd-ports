PORTNAME=	groonga
DISTVERSION=	16.0.5
CATEGORIES=	textproc
MASTER_SITES=	https://packages.groonga.org/source/groonga/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open-source fulltext search engine and column store
WWW=		https://groonga.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/rapidjson/document.h:devel/rapidjson
LIB_DEPENDS=	libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash

USES=		cmake libedit libtool localbase:ldflags pathfix pkgconfig shebangfix ssl
USE_LDCONFIG=	yes

SHEBANG_FILES= tools/object-inspect-all.sh \
		tools/index-column-diff-all.sh

CMAKE_ARGS=	-DGRN_LOG_PATH=/var/log/groonga.log
CMAKE_ON=	GRN_WITH_EXAMPLES GRN_WITH_MUNIN_PLUGINS GRN_WITH_TOOLS

OPTIONS_DEFINE=		MECAB RUBY SUGGEST
OPTIONS_DEFAULT=	MECAB RUBY
OPTIONS_SUB=		yes

MECAB_DESC=	Morphological analysis support via MeCab
SUGGEST_DESC=	Suggestions support

MECAB_LIB_DEPENDS=	libmecab.so:japanese/mecab
MECAB_CMAKE_BOOL=	GRN_WITH_MECAB
RUBY_RUN_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler
RUBY_USES=		ruby
RUBY_CMAKE_BOOL=	GRN_WITH_MRUBY
SUGGEST_LIB_DEPENDS=	libevent.so:devel/libevent \
			libmsgpackc.so:devel/msgpack-c \
			libzmq.so:net/libzmq4
SUGGEST_CMAKE_BOOL=	GRN_WITH_LIBEVENT GRN_WITH_MESSAGE_PACK GRN_WITH_ZEROMQ

.include <bsd.port.mk>
