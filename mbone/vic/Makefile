# New ports collection makefile for:	vic
# Date created:		14 December 1994
# Whom:			wollman
#
# $FreeBSD$
#

PORTNAME=	vic
PORTVERSION=	2.8
CATEGORIES=	mbone tk82
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DISTFILES=	vicsrc-2.8.tar.gz

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_AUTOCONF=	yes
USE_X_PREFIX=	yes
MAN1=		vic.1

post-install:
	strip ${PREFIX}/bin/vic
	strip ${PREFIX}/bin/histtolut

.include <bsd.port.mk>
