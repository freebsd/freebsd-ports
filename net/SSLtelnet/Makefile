# New ports collection makefile for:	SSLtelnet
# Date created:		Mar 29, 1998
# Whom:			issei@jp.FreeBSD.org
#
# $FreeBSD$

PORTNAME=		SSLtelnet
PORTVERSION=		0.13
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.psy.uq.oz.au/pub/Crypto/SSLapps/

MAINTAINER=		issei@jp.FreeBSD.org

USE_OPENSSL=   RSA

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

post-install:
	strip $(PREFIX)/bin/telnet
	strip $(PREFIX)/libexec/telnetd

.include <bsd.port.mk>
