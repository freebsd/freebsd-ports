# New ports collection makefile for:	icqmail
# Date created:		9 Jun 2000
# Whom:			Michael Vasilenko <acid@cn.ua>
#
# $FreeBSD$
#

PORTNAME=	icqmail
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	never@nevermind.kiev.ua

LIB_DEPENDS=	icq0.1:${PORTSDIR}/net/icqlib0 \
		guile.9:${PORTSDIR}/lang/guile \
		mimelib.3:${PORTSDIR}/converters/kdesupport2

USE_NEWGCC=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		LIBS="-L${LOCALBASE}/lib -lguile -lqthreads"

MAN1=		icqmail.1

.include <bsd.port.mk>
