# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	libnet
PORTVERSION=	1.1.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/libnet-dev
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A C library for creating IP packets

LATEST_LINK=	${PORTNAME}${SHORT_VER}

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC
USE_CSTD=	gnu89
CONFIGURE_ARGS=	--with-link-layer=${LIBNET_LINK}

SHORT_VER=	11
SHORT_NAME=	${PORTNAME}${SHORT_VER}
DOCSDIR=	${PREFIX}/share/doc/${SHORT_NAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${SHORT_NAME}
USE_LDCONFIG=	${PREFIX}/lib/${SHORT_NAME}
PLIST_SUB=	SVER=${SHORT_VER} SNAME=${SHORT_NAME} VERSION=${PORTVERSION}

DOCS=		README doc/CHANGELOG doc/CONTRIB doc/COPYING \
		doc/DESIGN_NOTES doc/MIGRATION doc/PACKET_BUILDING doc/PORTED \
		doc/RAWSOCKET_NON_SEQUITUR doc/TODO
EXAMPLES=	sample/*.c

OPTIONS_DEFINE=	EXAMPLES DOCS BPF
OPTIONS_DEFAULT=	BPF
BPF_DESC=	link layer bpf

.include <bsd.port.options.mk>

LIBNET_LINK=	none

.if ${PORT_OPTIONS:MBPF}
LIBNET_LINK=	bpf
.endif

post-patch:
	${REINPLACE_CMD} \
	 -e 's|@LIBNET_CONFIG_LIBS@|@LIBNET_CONFIG_LIBS@ -L@prefix@/lib/${SHORT_NAME}|' \
	 -e 's|@LIBNET_CONFIG_CFLAGS@|@LIBNET_CONFIG_CFLAGS@ -I@prefix@/include/${SHORT_NAME}|' \
		${WRKSRC}/libnet-config.in
	${REINPLACE_CMD} -e 's|^includedir =.*|includedir = @includedir@/${SHORT_NAME}|' \
		${WRKSRC}/include/Makefile.in \
		${WRKSRC}/include/libnet/Makefile.in
	${REINPLACE_CMD} -e 's|^libdir =.*|libdir = @libdir@/${SHORT_NAME}|' \
		-e 's|^libnet_la_LDFLAGS =\(.*\)|libnet_la_LDFLAGS =\1 -soname=libnet-${SHORT_NAME}.so.1|' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libnet-config ${STAGEDIR}${PREFIX}/bin/${SHORT_NAME}-config
	@cd ${STAGEDIR}${PREFIX}/lib && \
		${LN} -sf ${SHORT_NAME}/libnet.so libnet-${PORTVERSION}.so.8 && \
		${LN} -sf libnet-${PORTVERSION}.so.8 libnet-${PORTVERSION}.so
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
