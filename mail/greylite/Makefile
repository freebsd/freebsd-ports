PORTNAME=	greylite
PORTVERSION=	2.3
PORTREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	https://github.com/OlliL/greylite/releases/download/v${PORTVERSION}/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Modified greylisting for qmail and for any other MDA
WWW=		https://github.com/OlliL/greylite/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	tcpserver:sysutils/ucspi-tcp

USES=		sqlite tar:bzip2
PLIST_FILES=	bin/greylite \
		share/man/man8/greylite.8.gz
DNSBLENV_PLIST_FILES=	bin/dnsblenv
UCSPI2SOCKET_PLIST_FILES=	bin/ucspi2socket

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DNSBLENV UCSPI2SOCKET
OPTIONS_DEFAULT=	DNSBLENV UCSPI2SOCKET
DNSBLENV_DESC=		Module for interfacing with DNS blacklists
UCSPI2SOCKET_DESC=	Module for using greylite as SMTP proxy

.include <bsd.port.pre.mk>

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
		-e 's,/man/,/share/man/,g' \
		-e 's,logmsg.c logmsg.h ucspi2socket.c,logmsg.o ucspi2socket.c,' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
