# New ports collection makefile for:	kbedic
# Date created:			17 January 2002
# Whom:				Angel Todorov <todorov_bg@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	kbedic
PORTVERSION=	4.0
PORTREVISION=	7
CATEGORIES=	textproc kde
MASTER_SITES=	SF/${PORTNAME}/KBE%20Dictionary/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An English-Bulgarian-English dictionary

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS+=	--with-kde
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
USE_KDELIBS_VER=	3

.include <bsd.port.mk>
