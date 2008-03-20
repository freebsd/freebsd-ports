# New ports collection makefile for:	arpalert
# Date created:				11 May 2006
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arpalert
PORTVERSION=	2.0.9
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.arpalert.org/src/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	ARP traffic monitoring

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
ALL_TARGET=	${PORTNAME}
CFLAGS+=        -fPIC

MAN8=		arpalert.8

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
