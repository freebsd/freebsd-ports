# New ports collection makefile for:	crawl
# Date created:				20 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	crawl
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	petef@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
LIB_DEPENDS=	md5.1:${PORTSDIR}/www/libwww \
		db3.3:${PORTSDIR}/databases/db3

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_REINPLACE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}
CONFIGURE_ENV=	LIBS="${LDFLAGS} -L${LOCALBASE}/lib -lmd5"

MAN1=	crawl.1

post-patch:
	@${REINPLACE_CMD} -e 's,-ldb,-ldb3,g' ${WRKSRC}/configure.in
	${CHMOD} u+w ${WRKSRC}/*

.include <bsd.port.mk>
