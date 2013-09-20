# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bwm-ng
PORTVERSION=	0.6
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.gropp.org/bwm-ng/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	A small and simple bandwidth monitor

LIB_DEPENDS=	statgrab.8:${PORTSDIR}/devel/libstatgrab

GNU_CONFIGURE=	yes
USES=		pkgconfig
MAN1=		bwm-ng.1
PLIST_FILES=	bin/bwm-ng

CONFIGURE_ENV=	LIBS="`pkg-config --libs libstatgrab`"

NO_STAGE=	yes
.include <bsd.port.mk>
