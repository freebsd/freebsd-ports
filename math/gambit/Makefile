# Created by: ijliao
# $FreeBSD$

PORTNAME=	gambit
PORTVERSION=	13.0.1
CATEGORIES=	math
MASTER_SITES=	SF/gambit/${PORTNAME}13/${PORTVERSION}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A library of tools for doing computation in game theory

LICENSE=	GPLv2

USE_GNOME=	gtk20
USE_WX=		2.8+
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-wx-config=${WX_CONFIG}

.include <bsd.port.mk>
