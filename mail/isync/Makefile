# New ports collection makefile for:   isync
# Date created:		2000-12-23
# Whom:			eivind
#
# $FreeBSD$

PORTNAME=	isync
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.cs.hmc.edu/~me/isync/

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

MAINTAINER=	eivind@FreeBSD.org

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/db3" \
		LIBS="-L${LOCALBASE}/lib" \
		LDFLAGS="-ldb3"

MAN1=		isync.1

.include <bsd.port.mk>
