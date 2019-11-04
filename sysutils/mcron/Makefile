# Created by: ijliao
# $FreeBSD$

PORTNAME=	mcron
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	100% compatible replacement for Vixie cron

LIB_DEPENDS=	libguile-2.2.so:lang/guile2

USES=		pkgconfig
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

INFO=		mcron

post-patch:
	@${REINPLACE_CMD} -e 's,guile-2\.0,guile-2.2,' \
		${WRKSRC}/configure

.include <bsd.port.mk>
