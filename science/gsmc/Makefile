# Created by: db
# $FreeBSD$

PORTNAME=	gsmc
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	science hamradio
MASTER_SITES=	http://www.qsl.net/ik5nax/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Smith chart program for impedance matching

LICENSE=	GPLv2

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USES=		autoreconf gmake pkgconfig
PLIST_FILES=	bin/gsmc man/man1/gsmc.1.gz

post-patch:
	@${REINPLACE_CMD} '/^LIBS=/s/$$/ -lm/' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
