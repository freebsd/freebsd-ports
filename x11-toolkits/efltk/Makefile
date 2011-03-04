# New ports collection makefile for:	efltk
# Date created:				27 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	efltk
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/ede/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extended Fast Light Toolkit

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386

.if defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=	--disable-mysql
.else
USE_MYSQL=	yes
.endif

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	autoconf213
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		DEBUGFLAG="${CFLAGS} -I${LOCALBASE}/include"
MAKE_ENV+=	LD_LIBRARY_PATH="${WRKSRC}/lib"

USE_LDCONFIG=	yes
USE_XORG=	x11 xext

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
BROKEN=	does not build
.endif

.include <bsd.port.post.mk>
