# New ports collection makefile for:    sendfile
# Date created:         30 Oct 1997
# Whom:                 sec@42.org
#
# $FreeBSD$
#

PORTNAME=	sendfile
PORTVERSION=	2.1a
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.belwue.de/pub/unix/sendfile/current/
DISTFILES=	sendfile-20010216.tar.gz

MAINTAINER=	sec@42.org
COMMENT=	Simple Asynchronous File Transfer Reference Implementation

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=makeconfig
CONFIGURE_ENV=	PREFIX="${PREFIX}"

MAN1=		sendfile.1 sendmsg.1 receive.1 fetchfile.1 utf7encode.1 \
		wlock.1
MAN7=		fetchfile.7
MAN8=		sendfiled.8
MLINKS=		utf7encode.1 utf7decode.1

.include <bsd.port.mk>
