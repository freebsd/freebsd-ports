# Created by: kris@FreeBSD.org
# $FreeBSD$

PORTNAME=	libnids
PORTVERSION=	1.24
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	wxs@FreeBSD.org
COMMENT?=	Network monitoring library with TCP/IP reassembly

LICENSE=	GPLv2

CONFLICTS?=	libnids-libnet11-[0-9]*

OPTIONS_DEFINE=	LIBNET10 LIBNET11 GLIB2
LIBNET10_DESC=	Use libnet 1.0.x
LIBNET11_DESC=	Use libnet 1.1.x
GLIB2_DESC=	Use GLIB2 for multiprocessing support
OPTIONS_SUB=	yes
.if defined(WITH_LIBNET11)
OPTIONS_DEFAULT=	LIBNET11 GLIB2
.else
OPTIONS_DEFAULT=	LIBNET10 GLIB2
.endif

GLIB2_USE=	gnome=glib20
GLIB2_CONFIGURE_ENABLE=	libglib

WANT_GNOME=	yes
USES=		pkgconfig
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBNET10}
LIBNET_VERSION=	10
BUILD_DEPENDS+=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet${LIBNET_VERSION}
LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet${LIBNET_VERSION}-config
LIBNET_LIB=	"-L${LOCALBASE}/include/libnet${LIBNET_VERSION} \
		${LOCALBASE}/lib/libnet${LIBNET_VERSION}/libnet.a"
.elif ${PORT_OPTIONS:MLIBNET11}
LIBNET_VERSION=	11
BUILD_DEPENDS+=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet${LIBNET_VERSION}-config
LIBNET_LIB=	"`${LIBNET_CONFIG} --libs`"
.else
CONFIGURE_ARGS+=	--disable-libnet
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|(LNET_CFLAGS=).*|\1"`${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --cflags`"|; \
		 s|(LNETLIB=).*|\1${LIBNET_LIB}|' \
		 ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/nids.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libnids.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/src/libnids.3 ${STAGEDIR}${MAN3PREFIX}/man/man3
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README doc/* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
