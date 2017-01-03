# $FreeBSD$

PORTNAME=	axa
PORTVERSION=	1.4.0
CATEGORIES=	net dns
MASTER_SITES=	FARSIGHT/${PORTNAME} LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	AXA library and tools

LICENSE=	APACHE20 PD
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/copyright
LICENSE_FILE_PD=	${WRKSRC}/license_pd

BUILD_DEPENDS=	bash:shells/bash \
		sie-nmsg>0:net/sie-nmsg
LIB_DEPENDS=	libcheck.so:devel/libcheck \
		libprotobuf-c.so:devel/protobuf-c \
		libnmsg.so:net/nmsg \
		libwdns.so:dns/wdns \
		libyajl.so:devel/yajl
RUN_DEPENDS=	sie-nmsg>0:net/sie-nmsg

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libedit libtool pathfix pkgconfig shebangfix \
		ssl
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
USE_LDCONFIG=	yes
SHEBANG_FILES=	cert_tools/axa_link_certs.in

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=DOXYGEN

ALL_TARGET=	all
INSTALL_TARGET=	install-strip
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	html-local

LDFLAGS+=	-lm

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
CONFIGURE_ENV+=	libcrypto_CFLAGS="-I${OPENSSLINC}"		\
		libcrypto_LIBS="${OPENSSLLIB}/libcrypto.so"	\
		libssl_CFLAGS="-I${OPENSSLINC}"			\
		libssl_LIBS="${OPENSSLLIB}/libssl.so"
.endif

post-extract:
	(${ECHO} "For libmy/b64_encode.c:" ; \
	 ${SED} -ne "1,/\*\//p" ${WRKSRC}/libmy/b64_encode.c ) > ${LICENSE_FILE_PD}

post-install-DOXYGEN-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
