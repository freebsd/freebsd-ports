# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	fetion
PORTVERSION=	0.98.5.2
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	http://www.logvinov.ru/files/dist/fetion/ \
		LOCAL/avl
PKGNAMEPREFIX=	pidgin-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fetion protocol plugin for libpurple

LIB_DEPENDS=	purple.10:${PORTSDIR}/net-im/libpurple

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.mk>
