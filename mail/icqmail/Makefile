# New ports collection makefile for:	icqmail
# Date created:		9 Jun 2000
# Whom:			Michael Vasilenko <acid@cn.ua>
#
# $FreeBSD$
#

PORTNAME=	icqmail
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	http://download.sourceforge.net/icqmail/ \
		ftp://download.sourceforge.net/pub/sourceforge/icqmail/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	icq.1:${PORTSDIR}/net/icqlib \
		mimelib.3:${PORTSDIR}/converters/kdesupport2 \
		guile.6:${PORTSDIR}/lang/guile

USE_NEW_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lguile -lqthreads"

.include <bsd.port.mk>
