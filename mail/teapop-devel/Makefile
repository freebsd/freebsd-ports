# New ports collection makefile for:	teapop
# Date created:			18 May 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	teapop
PORTVERSION= 	0.28
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.toontown.org/pub/teapop/ \
		http://www.toontown.org/pub/teapop/

MAINTAINER=	jim@FreeBSD.org

.if defined(WITH_PGSQL)
LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--enable-flock

.if defined(WITHOUT_APOP)
CONFIGURE_ARGS+=	--disable-apop
.endif

.if defined(WITHOUT_VPOP)
CONFIGURE_ARGS+=	--disable-vpop
.endif

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql=${PREFIX}/pgsql
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
.endif

MAN8=		teapop.8

.include <bsd.port.mk>
