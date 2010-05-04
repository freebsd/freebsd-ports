# New ports collection makefile for:  drood
# Date created:                       Sat, 07 Jul 2007 22:47:06 EDT
# Whom:                               James Bailie <jimmy@mammothcheese.ca>
#
# $FreeBSD$
#

PORTNAME=	drood
PORTVERSION=	1.56
CATEGORIES=	www
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Lightweight kqueue-based http/1.1 server

LIB_DEPENDS=	tre.5:${PORTSDIR}/textproc/libtre

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN8=		drood.8 plunger.8

MANCOMPRESSED=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
