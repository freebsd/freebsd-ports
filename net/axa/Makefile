# $FreeBSD$

PORTNAME=	axa
PORTVERSION=	1.2.1
CATEGORIES=	net dns
MASTER_SITES=	FARSIGHT/${PORTNAME}/${PORTVERSION} LOCAL/truckman/farsight
DISTNAME=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	AXA library and tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/copyright

BUILD_DEPENDS=	bash:shells/bash \
		sie-nmsg>0:net/sie-nmsg
LIB_DEPENDS=	libprotobuf-c.so:devel/protobuf-c \
		libnmsg.so:net/nmsg \
		libwdns.so:dns/wdns
RUN_DEPENDS=	sie-nmsg>0:net/sie-nmsg

WRKSRC=		${WRKDIR}/axa-tools

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libedit libtool pathfix pkgconfig
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=DOXYGEN

ALL_TARGET=	all
INSTALL_TARGET=	install-strip
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	html-local

LDFLAGS+=	-lm

post-install-DOXYGEN-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
