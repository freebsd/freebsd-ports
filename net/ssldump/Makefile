# New ports collection makefile for:	ssldump
# Date created:		10 November 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssldump
PORTVERSION=	0.9b1
CATEGORIES=	net security
MASTER_SITES=	http://www.rtfm.com/ssldump/

MAINTAINER=	kris@FreeBSD.org

USE_OPENSSL=	YES

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

MAN1=		ssldump.1

.include <bsd.port.post.mk>
