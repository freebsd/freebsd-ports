# New ports collection makefile for:	nbsmtp
# Date created:		5 May 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#
# WITH_SSL=yes	"Support for secure connection to mail server"
#

PORTNAME=	nbsmtp
PORTVERSION=	0.99
CATEGORIES=	mail
PORTREVISION=	1
MASTER_SITES=	http://www.gentoo-es.org/~ferdy/ \
		http://www.it.uc3m.es/~ferdy/nbsmtp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple program for outgoing SMTP delivery

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

OPTIONS=	IPV6	"Support for IPv6 connections"			off \
		DEBUG	"Enable debug information (for developers)"	off \
		SSL	"Enable SSL support"				off

PLIST_FILES=	bin/nbsmtp

MAN5=	nbsmtprc.5
MAN8=	nbsmtp.8

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-ssl
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.post.mk>
