# New ports collection makefile for:	kbedic
# Date created:			17 January 2002
# Whom:				Angel Todorov <todorov_bg@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	kbedic
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://kbedic.search.bg/download/
MASTER_SITE_SUBDIR=kbedic

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An English-to-Bulgarian and Bulgarian-to-English dictionary

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-kde
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
USE_KDELIBS_VER=	3

.include <bsd.port.mk>
