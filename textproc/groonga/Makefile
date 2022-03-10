PORTNAME=	groonga
PORTVERSION=	12.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://packages.groonga.org/source/groonga/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open-source fulltext search engine and column store

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gmake libedit libtool pathfix pkgconfig
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

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		MECAB RUBY SUGGEST
OPTIONS_DEFAULT=	MECAB RUBY SUGGEST
OPTIONS_SUB=		yes

MECAB_DESC=	Morphological analysis support via MeCab
SUGGEST_DESC=	Suggestions support

MECAB_LIB_DEPENDS=	libmecab.so:japanese/mecab
MECAB_CONFIGURE_OFF=	--without-mecab
RUBY_RUN_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler
RUBY_USE=		RUBY=yes
RUBY_CONFIGURE_ON=	--enable-mruby
SUGGEST_LIB_DEPENDS=	libevent.so:devel/libevent \
			libmsgpackc.so:devel/msgpack \
			libzmq.so:net/libzmq2
SUGGEST_CONFIGURE_ON=	--enable-zeromq \
			--with-libevent=${LOCALBASE} \
			--with-message-pack=${LOCALBASE}
SUGGEST_CONFIGURE_OFF=	--disable-zeromq \
			--without-libevent \
			--without-message-pack

post-patch:
	@${REINPLACE_CMD} -e \
		's|lib/$${PACKAGE}/db/db|db/$${PACKAGE}/db| ; \
		 s|-lpthread|-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/NGX_PID_PATH/s|mkdir|${TRUE}| ; \
		 /NGX_HTTP_LOG_PATH/s|mkdir|${TRUE}| ; \
		 /NGX_ERROR_LOG_PATH/s|mkdir|${TRUE}|' \
		${WRKSRC}/vendor/nginx-1.21.6/auto/install
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${MV} ${WRKSRC}/version ${WRKSRC}/version.txt
	@${REINPLACE_CMD} -Ei .c++20 '/test|cat/s/[[:<:]]version/&.txt/' \
		${WRKSRC}/version-gen.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/groonga-httpd
	@${MKDIR} ${STAGEDIR}/var/log/groonga/httpd
	@${MKDIR} ${STAGEDIR}/var/run/groonga

.include <bsd.port.mk>
