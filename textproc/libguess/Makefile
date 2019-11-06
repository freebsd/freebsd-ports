# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libguess
PORTVERSION=	1.1
CATEGORIES=	textproc devel
MASTER_SITES=	http://distfiles.atheme.org/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	High-speed character set detection library

BROKEN=		unfetchable

LIB_DEPENDS=	libmowgli.so:devel/libmowgli

USES=		gmake pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}"

.include <bsd.port.mk>
