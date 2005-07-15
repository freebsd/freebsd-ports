# New ports collection makefile for:	efltk
# Date created:				27 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	efltk
PORTVERSION=	2.0.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ede

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Extended Fast Light Toolkit

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386

.if defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=	--disable-mysql
.else
USE_MYSQL=	yes
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		DEBUGFLAG="${CFLAGS} -I${LOCALBASE}/include"

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
