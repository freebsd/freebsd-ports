# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	exmpp
PORTVERSION=	0.9.9
CATEGORIES=	textproc net-im

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Fast and scalable library for XMPP written in Erlang/OTP

LICENSE=	EPL

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang
LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libxml2.so:${PORTSDIR}/textproc/libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	processone
GH_PROJECT=	exmpp
GH_COMMIT=	829cdc2
GH_TAGNAME=	v${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-static=yes \
		--enable-shared=yes \
		--with-erlang=${LOCALBASE} \
		--with-expat=${LOCALBASE} \
		--with-openssl=/usr \
		--disable-debug \
		--disable-warnings \
		--disable-examples \
		--enable-escaping-using-cdata
GNU_CONFIGURE_PREFIX=	"${PREFIX}/lib/erlang/lib"
PLIST_SUB=	VERSION=${PORTVERSION}
USE_AUTOTOOLS=	autoconf:env automake:env libtoolize:env
USES=		libtool pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--enable-documentation
.else
CONFIGURE_ARGS+=	--disable-documentation
.endif

MAKE_JOBS_UNSAFE=	yes

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -ivf

post-configure:
	${MAKE} clean -C ${WRKSRC}

post-install:
.for _file in exmpp_xml_expat_legacy.so exmpp_compress_zlib.so		\
	exmpp_xml_expat.so exmpp_stringprep.so exmpp_xml_libxml2.so	\
	exmpp_tls_openssl.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv/lib/${_file}
.endfor

.include <bsd.port.mk>
