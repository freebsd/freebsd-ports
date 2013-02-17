# $FreeBSD$

PORTNAME=	groonga
PORTVERSION=	3.0.0
CATEGORIES=	textproc
MASTER_SITES=	http://packages.groonga.org/source/groonga/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Open-source fulltext search engine and column store

LICENSE=	LGPL21
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
USE_GMAKE=      yes
CONFIGURE_ARGS=	--with-munin-plugins 
CONFIGURE_ARGS+=	--with-log-path=/var/log/groonga.log \
			--localstatedir=/var

OPTIONS_DEFINE=	MECAB SUGGEST
MECAB_DESC=	use mecab for morphological analysis
SUGGEST_DESC=	use suggest for suggest
OPTIONS_DEFAULT=MECAB SUGGEST

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

# We cannot enable this document option until textproc/py-sphinx be upgraded to 1.2.
.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
MAN1=	groonga.1
.else
CONFIGURE_ARGS+=	--disable-document
.endif

.if ${PORT_OPTIONS:MMECAB} || exists(${LOCALBASE}/lib/libmecab.so)
CONFIGURE_ARGS+=	--with-mecab
LIB_DEPENDS+=	mecab:${PORTSDIR}/japanese/mecab
PLIST_SUB+=	MECAB=""
.else
CONFIGURE_ARGS+=	--without-mecab
PLIST_SUB+=	MECAB="@comment "
.endif

.if ${PORT_OPTIONS:MSUGGEST}
CONFIGURE_ARGS+=	--with-libevent=${LOCALBASE} \
			--with-message-pack=${LOCALBASE} \
			--enable-zeromq
LIB_DEPENDS+=	event-1.4:${PORTSDIR}/devel/libevent \
		msgpack:${PORTSDIR}/devel/msgpack \
		zmq:${PORTSDIR}/devel/zmq
PLIST_SUB+=	SUGGEST=""
.else
CONFIGURE_ARGS+=	--without-libevent \
			--without-message-pack \
			--disable-zeromq
PLIST_SUB+=	SUGGEST="@comment "
.endif

.include <bsd.port.post.mk>
