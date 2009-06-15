# New ports collection makefile for:	greylite
# Date created:		2007-12-11
# Whom:			Mij <mij@bitchx.it>
#
# $FreeBSD$
#

PORTNAME=	greylite
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://mij.oltrelinux.com/net/greylite/releases/

MAINTAINER=	mij@bitchx.it
COMMENT=	Modified greylisting for qmail and for any other MDA

RUN_DEPENDS=	tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

USE_BZIP2=	yes
USE_SQLITE=	3
PLIST_FILES=	bin/greylite \
		%%DNSBLENV%%bin/dnsblenv	\
		%%UCSPI2SOCKET%%bin/ucspi2socket

MAN8=		greylite.8
MANCOMPRESSED=	yes

OPTIONS=	GEOIP		"Support for GeoIP in suspicion rules" On \
		DNSBLENV   	"Module for interfacing with DNS blacklists" On \
		UCSPI2SOCKET "Module for using greylite as SMTP proxy" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GEOIP)
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
MAKE_ARGS+=	WITH_GEOIP=yep
.endif

.if !defined(WITHOUT_DNSBLENV)
LIB_DEPENDS+=	cares:${PORTSDIR}/dns/c-ares
MAKE_ARGS+=	WITH_DNSBLENV=yep
PLIST_SUB+=	DNSBLENV=""
.else
PLIST_SUB+=	DNSBLENV="@comment "
.endif

.if !defined(WITHOUT_UCSPI2SOCKET)
MAKE_ARGS+=	WITH_UCSPI2SOCKET=yep
PLIST_SUB+=	UCSPI2SOCKET=""
.else
PLIST_SUB+=	UCSPI2SOCKET="@comment "
.endif

post-patch:
	${CP} ${WRKSRC}/Makefile.bsdmake ${WRKSRC}/Makefile

do-build:
	${MAKE} -C ${WRKSRC} ${MAKE_ARGS}

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
