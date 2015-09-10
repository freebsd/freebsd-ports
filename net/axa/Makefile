# $FreeBSD$

PORTNAME=	axa
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	tags/v
CATEGORIES=	net dns

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
USES=		autoreconf gmake libedit libtool pathfix pkgconfig
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
USE_GITHUB=	yes
GH_ACCOUNT=	farsightsec
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=DOXYGEN

ALL_TARGET=	all
INSTALL_TARGET=	install-strip
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXYGEN_ALL_TARGET=	html-local

LDFLAGS+=	-lm

post-install-DOXYGEN-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
