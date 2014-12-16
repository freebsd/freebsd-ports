# $FreeBSD$

PORTNAME=	axa
PORTVERSION=	1.0.0
CATEGORIES=	net dns

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	AXA library and tools

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		sie-nmsg>0:${PORTSDIR}/net/sie-nmsg
LIB_DEPENDS=	libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c \
		libnmsg.so:${PORTSDIR}/net/nmsg \
		libwdns.so:${PORTSDIR}/dns/wdns

USE_GITHUB=	yes
GH_ACCOUNT=	farsightsec
GH_COMMIT=	bf9c038
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=DOXYGEN

.include <bsd.port.options.mk>

ALL_TARGET=	all
.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
ALL_TARGET+=	html-local
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
post-install:
	(cd ${WRKSRC}/doc/doxygen && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
