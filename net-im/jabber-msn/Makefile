# New ports collection makefile for:	Jabber MSN Transport
# Date created:				Sat May 04 06:00:02 PDT 2002
# Whom:					Martijn Lina <martijn@pacno.net>
#
# $FreeBSD$

PORTNAME=	msn
PORTVERSION=	1.2.8.p10
CATEGORIES=	net
MASTER_SITES=	http://msn-transport.jabberstudio.org/
PKGNAMEPREFIX=	jabber-
DISTNAME=	${PORTNAME}-transport-${PORTVERSION:S/.p10/pre10/}

MAINTAINER=	martijn@pacno.net
COMMENT=	Jabber MSN-Transport module

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-jabberd=${PREFIX}/include/jabber \
		--with-pth=${PREFIX}/include/jabber
CONFIGURE_ENV=  LDFLAGS=-L${LOCALBASE}/lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/msntrans.so ${PREFIX}/lib/jabber/

.include <bsd.port.mk>
