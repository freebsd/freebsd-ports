# New ports collection makefile for:	knocker
# Date created:				Tue Jul 10 01:42:52 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	knocker
PORTVERSION=	0.4.0
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

USE_AUTOCONF=	yes

MAN1=		${PORTNAME}.1

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

.include <bsd.port.mk>
