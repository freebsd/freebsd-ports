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
USES=		gmake pkgconfig
USE_AUTOTOOLS=	aclocal automake autoconf
AUTOMAKE_ARGS=	-i --add-missing --foreign --copy --force

post-patch:
	@${REINPLACE_CMD} '/^LIBS=/s/$$/ -lm/' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
