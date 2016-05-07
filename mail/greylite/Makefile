# Created by: Mij <mij@bitchx.it>
# $FreeBSD$

PORTNAME=	greylite
PORTVERSION=	2.3
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	LOCAL/oliver

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Modified greylisting for qmail and for any other MDA

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	tcpserver:sysutils/ucspi-tcp

USES=		sqlite tar:bzip2
PLIST_FILES=	bin/greylite \
		%%DNSBLENV%%bin/dnsblenv	\
		%%UCSPI2SOCKET%%bin/ucspi2socket \
		man/man8/greylite.8.gz

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		GEOIP DNSBLENV UCSPI2SOCKET
OPTIONS_DEFAULT=	GEOIP DNSBLENV UCSPI2SOCKET
GEOIP_DESC=		Support for GeoIP in suspicion rules
DNSBLENV_DESC=		Module for interfacing with DNS blacklists
UCSPI2SOCKET_DESC=	Module for using greylite as SMTP proxy

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGEOIP}
LIB_DEPENDS+=	libGeoIP.so:net/GeoIP
MAKE_ARGS+=	WITH_GEOIP=yep
.endif

.if ${PORT_OPTIONS:MDNSBLENV}
LIB_DEPENDS+=	libcares.so:dns/c-ares
MAKE_ARGS+=	WITH_DNSBLENV=yep
PLIST_SUB+=	DNSBLENV=""
.else
PLIST_SUB+=	DNSBLENV="@comment "
.endif

.if ${PORT_OPTIONS:MUCSPI2SOCKET}
MAKE_ARGS+=	WITH_UCSPI2SOCKET=yep
PLIST_SUB+=	UCSPI2SOCKET=""
.else
PLIST_SUB+=	UCSPI2SOCKET="@comment "
.endif

post-patch:
	${CP} ${WRKSRC}/Makefile.bsdmake ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|PREFIX\?=.*|PREFIX=${STAGEDIR}${PREFIX}|g' \
		-e 's,logmsg.c logmsg.h ucspi2socket.c,logmsg.o ucspi2socket.c,' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
