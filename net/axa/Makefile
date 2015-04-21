# $FreeBSD$

PORTNAME=	axa
PORTVERSION=	1.1.1
CATEGORIES=	net dns
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	AXA library and tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/copyright

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		sie-nmsg>0:${PORTSDIR}/net/sie-nmsg
LIB_DEPENDS=	libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c \
		libnmsg.so:${PORTSDIR}/net/nmsg \
		libwdns.so:${PORTSDIR}/dns/wdns
RUN_DEPENDS=	sie-nmsg>0:${PORTSDIR}/net/sie-nmsg

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=DOXYGEN

ALL_TARGET=	all
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXYGEN_ALL_TARGET=	html-local

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
post-install:
	# install-strip does not strip libaxa.so
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/libaxa.so.0.0.0
	(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
