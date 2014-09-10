# Created by: ijliao
# $FreeBSD$

PORTNAME=	gambit
PORTVERSION=	13.1.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/gambit/${PORTNAME}13/${PORTVERSION}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Library of tools for doing computation in game theory

LICENSE=	GPLv2

USE_GNOME=	gtk20
USE_WX=		3.0
WX_UNICODE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-wx-config=${WX_CONFIG}

.include <bsd.port.mk>
