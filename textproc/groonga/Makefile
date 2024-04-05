PORTNAME=	groonga
DISTVERSION=	13.0.5
CATEGORIES=	textproc
MASTER_SITES=	https://packages.groonga.org/source/groonga/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open-source fulltext search engine and column store
WWW=		https://groonga.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libedit libtool localbase:ldflags pathfix pkgconfig ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-benchmark \
		--disable-document \
		--localstatedir=/var \
		--with-log-path=/var/log/groonga.log \
		--with-munin-plugins \
		--without-cutter \
		--without-inkscape \
		--without-kytea \
		--without-lemon

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		MECAB RUBY SUGGEST
OPTIONS_DEFAULT=	MECAB RUBY
OPTIONS_SUB=		yes

MECAB_DESC=	Morphological analysis support via MeCab
SUGGEST_DESC=	Suggestions support

MECAB_LIB_DEPENDS=	libmecab.so:japanese/mecab
MECAB_CONFIGURE_OFF=	--without-mecab
RUBY_RUN_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler
RUBY_USES=		ruby
RUBY_CONFIGURE_ON=	--enable-mruby
SUGGEST_BROKEN=		"Does not build with libzmq4"
SUGGEST_LIB_DEPENDS=	libevent.so:devel/libevent \
			libmsgpackc.so:devel/msgpack-c \
			libzmq.so:net/libzmq4
SUGGEST_CONFIGURE_ON=	--enable-zeromq \
			--with-libevent=${LOCALBASE} \
			--with-message-pack=${LOCALBASE}
SUGGEST_CONFIGURE_OFF=	--disable-zeromq \
			--without-libevent \
			--without-message-pack

post-patch:
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${MV} ${WRKSRC}/version ${WRKSRC}/version.txt
	@${REINPLACE_CMD} -Ei .c++20 '/test|cat/s/[[:<:]]version/&.txt/' \
		${WRKSRC}/version-gen.sh

.include <bsd.port.mk>
