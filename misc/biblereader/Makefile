# New ports collection makefile for:	biblereader
# Date created:        16 April 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	biblereader
PORTVERSION=	0.2.2
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.whitevine.com/biblereader/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} kjv.tar.gz
#EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	patseal@hyperhost.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
MAKE_ENV=	GTK_CONFIG=${GTK_CONFIG}

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

post-extract:
	${CP} ${WRKDIR}/kjv/kjv ${WRKSRC}/kjv.txt

.include <bsd.port.mk>
