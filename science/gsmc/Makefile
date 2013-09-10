# Created by: db
# $FreeBSD$

PORTNAME=	gsmc
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	science hamradio
MASTER_SITES=	http://www.qsl.net/ik5nax/

MAINTAINER=	db@FreeBSD.org
COMMENT=	Smith chart program for impedance matching

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gmake pkgconfig
USE_AUTOTOOLS=	aclocal automake autoconf
AUTOMAKE_ARGS=	-i --add-missing --foreign --copy

MAN1=		gsmc.1
PLIST_FILES=	bin/gsmc

.include <bsd.port.mk>
