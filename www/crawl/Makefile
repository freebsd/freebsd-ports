# New ports collection makefile for:	crawl
# Date created:				20 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	crawl
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	petef@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
LIB_DEPENDS=	md5.1:${PORTSDIR}/www/libwww

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}
CONFIGURE_ENV=	LIBS="${LDFLAGS} -L${LOCALBASE}/lib -lmd5"

MAN1=	crawl.1

.include <bsd.port.mk>
