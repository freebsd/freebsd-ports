# $FreeBSD$

PORTNAME=	groonga
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://packages.groonga.org/source/groonga/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Open-source fulltext search engine and column store

LICENSE=	LGPL21

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-munin-plugins --localstatedir=/var \
		--with-log-path=/var/log/groonga.log

.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--disable-silent-rules
.endif

OPTIONS_DEFINE=	MECAB SUGGEST DOCS
MECAB_DESC=	Enable morphological analysis
SUGGEST_DESC=	Enable suggestions
OPTIONS_DEFAULT=MECAB SUGGEST

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		does not compile on ${ARCH}
.endif

# We cannot enable this option until textproc/py-sphinx be upgraded to 1.2
# XXX: but it is enabled now as DOCS are on by default, so what's going on?
.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
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
		zmq:${PORTSDIR}/net/libzmq2
PLIST_SUB+=	SUGGEST=""
.else
CONFIGURE_ARGS+=	--without-libevent \
			--without-message-pack \
			--disable-zeromq
PLIST_SUB+=	SUGGEST="@comment "
.endif

.include <bsd.port.post.mk>
