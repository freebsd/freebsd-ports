# Created by: Björn König <bkoenig@alpha-tierchen.de>
# $FreeBSD$

PORTNAME=	bcusdk
PORTVERSION=	0.0.4
CATEGORIES=	net
MASTER_SITES=	http://www.auto.tuwien.ac.at/~mkoegler/eib/
PKGNAMESUFFIX=	-eibd
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	The EIBnet/IP server of the BCU SDK

LIB_DEPENDS=	pthsem.20:${PORTSDIR}/devel/pthsem
BUILD_DEPENDS=	${LOCALBASE}/lib/libargp.a:${PORTSDIR}/devel/argp-standalone

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--enable-onlyeibd \
		--disable-usb \
		--enable-eibnetip \
		--enable-eibnetipserver \
		--enable-eibnetiptunnel \
		--enable-groupcache \
		CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib ${CFLAGS}"

OPTIONS_DEFINE=	JAVA EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA}
CONFIGURE_ARGS+=--enable-java
USE_JAVA=	yes
PLIST_SUB+=	JAVA=""
.else
PLIST_SUB+=	JAVA="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} "s,-ri,-Ei.bak," ${WRKSRC}/eibd/client/php/Makefile.in
	@${REINPLACE_CMD} "s, bcu,," ${WRKSRC}/eibd/Makefile.in
	@${REINPLACE_CMD} "s, php,," ${WRKSRC}/eibd/client/Makefile.in
.if ! ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} "s, examples,," ${WRKSRC}/eibd/Makefile.in
.else
	@${REINPLACE_CMD} -e "s,^\(examplesdir = \).*,\1${EXAMPLESDIR}," \
		-e "s,^\(bindir = \).*,\1${EXAMPLESDIR}/bin," \
		${WRKSRC}/eibd/examples/Makefile.in
.endif
.if ${PORT_OPTIONS:MJAVA}
	@${REINPLACE_CMD} "s,^\(javadir = \).*,\1${JAVASHAREDIR}," ${WRKSRC}/eibd/client/java/Makefile.in
.endif

.include <bsd.port.mk>
