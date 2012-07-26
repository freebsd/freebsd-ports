# New ports collection makefile for:	bwm-ng
# Date created:		19 February 2006
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bwm-ng
PORTVERSION=	0.6
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.gropp.org/bwm-ng/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	A small and simple bandwidth monitor

LIB_DEPENDS=	statgrab.8:${PORTSDIR}/devel/libstatgrab

GNU_CONFIGURE=	yes
USE_PKGCONFIG=	yes
MAN1=		bwm-ng.1
PLIST_FILES=	bin/bwm-ng

CONFIGURE_ENV=	LIBS="`pkg-config --libs libstatgrab`"

.include <bsd.port.mk>
