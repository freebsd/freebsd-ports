# New ports collection makefile for:	icqmail
# Date created:		9 Jun 2000
# Whom:			Michael Vasilenko <acid@cn.ua>
#
# $FreeBSD$
#

PORTNAME=	icqmail
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	icq.1:${PORTSDIR}/net/icqlib \
		mimelib.3:${PORTSDIR}/converters/kdesupport2 \
		guile.9:${PORTSDIR}/lang/guile

USE_NEWGCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lguile -lqthreads"

MAN1=		icqmail.1

.include <bsd.port.mk>
