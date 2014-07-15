# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	libnet
PORTVERSION=	1.1.6
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/libnet-dev

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for creating IP packets

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	BPF DOCS EXAMPLES
OPTIONS_DEFAULT=BPF
BPF_DESC=	link layer bpf

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
USES=		libtool

SHORT_NAME=	${PORTNAME}11
DOCSDIR=	${PREFIX}/share/doc/${SHORT_NAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${SHORT_NAME}
USE_LDCONFIG=	${PREFIX}/lib/${SHORT_NAME}
PLIST_SUB=	SNAME=${SHORT_NAME} VERSION=${PORTVERSION}

DOCS=		README doc/CHANGELOG doc/CONTRIB doc/COPYING \
		doc/DESIGN_NOTES doc/MIGRATION doc/PACKET_BUILDING doc/PORTED \
		doc/RAWSOCKET_NON_SEQUITUR doc/TODO
EXAMPLES=	sample/*.c

BPF_CONFIGURE_OFF=	--with-link-layer=none
BPF_CONFIGURE_ON=	--with-link-layer=bpf

post-patch:
	@${REINPLACE_CMD} \
		 -e 's|@LIBNET_CONFIG_LIBS@|@LIBNET_CONFIG_LIBS@ -L@prefix@/lib/${SHORT_NAME}|' \
		 -e 's|@LIBNET_CONFIG_CFLAGS@|@LIBNET_CONFIG_CFLAGS@ -I@prefix@/include/${SHORT_NAME}|' \
			${WRKSRC}/libnet-config.in
	@${REINPLACE_CMD} -e 's|^includedir =.*|includedir = @includedir@/${SHORT_NAME}|' \
		${WRKSRC}/include/Makefile.in \
		${WRKSRC}/include/libnet/Makefile.in
	@${REINPLACE_CMD} -e 's|^libdir =.*|libdir = @libdir@/${SHORT_NAME}|' \
		-e 's|^libnet_la_LDFLAGS =\(.*\)|libnet_la_LDFLAGS =\1 -soname=libnet-${SHORT_NAME}.so.1|' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libnet-config ${STAGEDIR}${PREFIX}/bin/${SHORT_NAME}-config
	${LN} -fs ${SHORT_NAME}/libnet.so.1 ${STAGEDIR}${PREFIX}/lib/libnet-${PORTVERSION}.so.1
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
