# $FreeBSD$

PORTNAME=	axa
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	net dns
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	AXA library and tools

LICENSE=	APACHE20 PD
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/copyright
LICENSE_FILE_PD=	${WRKSRC}/license_pd

BUILD_DEPENDS=	bash:shells/bash \
		sie-nmsg>0:net/sie-nmsg
LIB_DEPENDS=	liblmdb.so:databases/lmdb \
		libcheck.so:devel/check \
		libprotobuf-c.so:devel/protobuf-c \
		libnmsg.so:net/nmsg \
		libwdns.so:dns/wdns \
		libyajl.so:devel/yajl
RUN_DEPENDS=	sie-nmsg>0:net/sie-nmsg

USES=		autoreconf compiler gmake libedit libtool pathfix \
		pkgconfig shebangfix ssl

GNU_CONFIGURE=	yes
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
USE_LDCONFIG=	yes
SHEBANG_FILES=	tools/axa_link_certs.in

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_DEFAULT=DOXYGEN

ALL_TARGET=	all
INSTALL_TARGET=	install-strip
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	html-local
DOXYGEN_IMPLIES=	DOCS

LDFLAGS+=	-lm

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	libcrypto_CFLAGS="-I${OPENSSLINC}"	\
		libcrypto_LIBS="-lcrypto"		\
		libssl_CFLAGS="-I${OPENSSLINC}"		\
		libssl_LIBS="-lssl"

post-extract:
	(${ECHO} "For libmy/b64_encode.c:" ; \
	${SED} -ne "1,/\*\//p" ${WRKSRC}/libmy/b64_encode.c ) > ${LICENSE_FILE_PD}

.if ${CHOSEN_COMPILER_TYPE} == gcc
pre-configure:
	${REINPLACE_CMD} -e 's|-Wno-unused-command-line-argument||' ${WRKSRC}/configure.ac
.endif

post-install-DOXYGEN-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
