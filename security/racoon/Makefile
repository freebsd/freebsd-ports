# New ports collection makefile for:	racoon
# Date created:		4 July 2000
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	racoon
PORTVERSION=	20000705a
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	sumikawa@FreeBSD.org

.if !exists(/usr/lib/libipsec.so.1)
BROKEN=		"You must upgrade the OS"
.endif

USE_OPENSSL=	RSA

WRKSRC=		${WRKDIR}/${DISTNAME}/racoon
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=CPPFLAGS=-I${LOCALBASE}/include CFLAGS=-I${LOCALBASE}/include \
		LDFLAGS="-L${LOCALBASE}/lib -L${WRKSRC}/../libipsec"
CONFIGURE_ARGS+=--enable-debug
CONFIGURE_ARGS+=--enable-ipv6
CONFIGURE_ARGS+=--sysconfdir=${LOCALBASE}/etc

MAN5=		racoon.conf.5
MAN8=		racoon.8

pre-patch:
	${MV} ${WRKSRC}/racoon.8 ${WRKSRC}/racoon.8.in

pre-configure:
	(cd ${WRKSRC}/../libipsec; make)

.include <bsd.port.mk>
