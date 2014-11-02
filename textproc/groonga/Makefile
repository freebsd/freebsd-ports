# $FreeBSD$

PORTNAME=	groonga
PORTVERSION=	4.0.6.1
CATEGORIES=	textproc
MASTER_SITES=	http://packages.groonga.org/source/groonga/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source fulltext search engine and column store

LICENSE=	LGPL21

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-benchmark \
		--disable-document \
		--disable-silent-rules \
		--localstatedir=/var \
		--without-cutter \
		--without-inkscape \
		--without-kytea \
		--without-lemon \
		--with-log-path=/var/log/groonga.log \
		--with-munin-plugins
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PKGDEINSTALL=	${PKGINSTALL}

BROKEN_ia64=	does not compile on ia64
BROKEN_powerpc=	does not compile on powerpc
BROKEN_sparc64=	does not compile on sparc64

OPTIONS_DEFINE=		MECAB SUGGEST
OPTIONS_DEFAULT=	MECAB SUGGEST
OPTIONS_SUB=		yes

MECAB_DESC=		Morphological analysis support via MeCab
MECAB_LIB_DEPENDS=	libmecab.so:${PORTSDIR}/japanese/mecab
MECAB_CONFIGURE_OFF=	--without-mecab
SUGGEST_DESC=		Suggestions support
SUGGEST_LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2 \
			libmsgpack.so:${PORTSDIR}/devel/msgpack \
			libzmq.so:${PORTSDIR}/net/libzmq2
SUGGEST_CONFIGURE_ON=	--with-libevent=${LOCALBASE} \
			--with-message-pack=${LOCALBASE} \
			--enable-zeromq
SUGGEST_CONFIGURE_OFF=	--without-libevent \
			--without-message-pack \
			--disable-zeromq

.include <bsd.port.options.mk>

.if ${ARCH} == i386
USE_GCC=	any
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|lib/$${PACKAGE}/db/db|db/$${PACKAGE}/db| ; \
		 s|-lpthread|-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/NGX_PID_PATH/s|mkdir|${TRUE}| ; \
		 /NGX_HTTP_LOG_PATH/s|mkdir|${TRUE}| ; \
		 /NGX_ERROR_LOG_PATH/s|mkdir|${TRUE}|' \
		${WRKSRC}/vendor/nginx-1.7.6/auto/install

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/groonga-httpd

.include <bsd.port.mk>
