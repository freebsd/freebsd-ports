# $FreeBSD$

PORTNAME=	axa
PORTVERSION=	1.0.0
# Use GH_TAGNAME until USE_GITHUB can cope with / in DISTVERSIONPREFIX
#DISTVERSIONPREFIX=	tags/v
PORTREVISION=	1
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

USE_GITHUB=	yes
GH_ACCOUNT=	farsightsec
GH_TAGNAME=	tags/v${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
USE_LDCONFIG=	yes

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
	(cd ${WRKSRC}/doc/doxygen && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
