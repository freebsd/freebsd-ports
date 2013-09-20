# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	exmpp
PORTVERSION=	0.9.7
CATEGORIES=	textproc net-im
MASTER_SITES=	http://download.process-one.net/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	Fast and scalable library for XMPP written in Erlang/OTP

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-static=yes \
					--enable-shared=yes \
					--with-erlang=${LOCALBASE} \
					--with-expat=${LOCALBASE} \
					--with-openssl=/usr \
					--disable-debug \
					--disable-warnings \
					--disable-examples \
					--enable-escaping-using-cdata
GNU_CONFIGURE_PREFIX=	"${PREFIX}/lib/erlang/lib"
PLIST_SUB=	PORTNAME=${PORTNAME} \
		PORTVERSION=${PORTVERSION}
USE_AUTOTOOLS=	autoconf:env automake:env aclocal:env libtool:env autoheader:env

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-documentation
.else
CONFIGURE_ARGS+=	--enable-documentation
.endif

NO_STAGE=	yes
pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -ivf

post-configure:
	${MAKE} clean -C ${WRKSRC}

.include <bsd.port.mk>
