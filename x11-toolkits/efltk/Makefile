# New ports collection makefile for:	efltk
# Date created:				27 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	efltk
PORTVERSION=	2.0.8
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/ede/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extended Fast Light Toolkit

DEPRECATED=	Abandoned upstream, no ports depend on it
EXPIRATION_DATE=	2012-10-20

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386

USE_XORG=	x11 xext
USE_AUTOTOOLS=	autoconf213
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	DEBUGFLAG="${CFLAGS}"
MAKE_ENV=	LD_LIBRARY_PATH="${WRKSRC}/lib"
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=--disable-mysql
PLIST_SUB+=	MYSQL="@comment "
.else
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.endif

.include <bsd.port.post.mk>
