# Created by: smace@freebsd.org
# $FreeBSD$

PORTNAME=	libnet
PORTVERSION=	1.1.6
CATEGORIES=	net
MASTER_SITES=	SF/libnet-dev

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A C library for creating IP packets (development version)

LATEST_LINK=	${PORTNAME}${SHORT_VER}

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-link-layer=${LIBNET_LINK}

SHORT_VER=	116
SHORT_NAME=	${PORTNAME}${SHORT_VER}
DOCSDIR=	${PREFIX}/share/doc/${SHORT_NAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${SHORT_NAME}
USE_LDCONFIG=	${PREFIX}/lib/${SHORT_NAME}
PLIST_SUB=	SVER=${SHORT_VER} SNAME=${SHORT_NAME} VERSION=${PORTVERSION}

MAN3=		libnet-functions.h.3 libnet-macros.h.3 libnet.h.3
DOCS=		README doc/CHANGELOG doc/CONTRIB doc/COPYING \
		doc/DESIGN_NOTES doc/MIGRATION doc/PACKET_BUILDING doc/PORTED \
		doc/RAWSOCKET_NON_SEQUITUR doc/TODO

EXAMPLES=	sample/*.c

OPTIONS=	NONE "link layer none" off \
		SNOOP "link layer (snoop.h)" off \
		PF "link layer pf" off \
		BPF "link layer bpf" on

.if defined(WITH_NONE)
LIBNET_LINK=	none
.elif defined(WITH_SNOOP)
LIBNET_LINK=	snoop
.elif defined(WITH_PF)
LIBNET_LINK=	pf
.elif defined(WITHOUT_BPF)
LIBNET_LINK=	none
.else
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
	${INSTALL_SCRIPT} ${WRKSRC}/libnet-config ${PREFIX}/bin/${SHORT_NAME}-config
	@cd ${PREFIX}/lib && \
		${LN} -sf ${SHORT_NAME}/libnet.so libnet-${PORTVERSION}.so.8 && \
		${LN} -sf libnet-${PORTVERSION}.so.8 libnet-${PORTVERSION}.so
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
