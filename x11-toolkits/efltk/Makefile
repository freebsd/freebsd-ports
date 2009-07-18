# New ports collection makefile for:	efltk
# Date created:				27 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	efltk
PORTVERSION=	2.0.7
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/ede

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Extended Fast Light Toolkit

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386

.if defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=	--disable-mysql
.else
USE_MYSQL=	yes
.endif

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	autoconf:213
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		DEBUGFLAG="${CFLAGS} -I${LOCALBASE}/include"
MAKE_ENV+=	LD_LIBRARY_PATH="${WRKSRC}/lib"

USE_LDCONFIG=	yes
USE_XORG=	x11 xext

.include <bsd.port.mk>
