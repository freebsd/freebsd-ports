# New ports collection makefile for:	kbedic
# Date created:			17 January 2002
# Whom:				Angel Todorov <todorov_bg@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	kbedic
PORTVERSION=	4.0
PORTREVISION=	5
CATEGORIES=	textproc kde
MASTER_SITES=	SF/${PORTNAME}/KBE%20Dictionary/${PORTVERSION}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An English-Bulgarian-English dictionary

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS+=	--with-kde
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
USE_KDELIBS_VER=	3

.include <bsd.port.mk>
