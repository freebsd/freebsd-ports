# New ports collection makefile for:	echoping
# Date created:		13 April 1997
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	echoping
PORTVERSION=	4.2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	ports@FreeBSD.org

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-http --enable-icp --enable-smtp --with-ssl \
		--enable-ttcp --enable-tos

MAN1=		echoping.1

.include <bsd.port.mk>
