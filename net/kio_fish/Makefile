# New ports collection makefile for:	kio_fish
# Date created:				Mon 26 Nov 2001
# Whom:					Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	kio_fish
PORTVERSION=	1.0.1
CATEGORIES?=	net kde
MASTER_SITES=	http://ich.bin.kein.hoschi.de/fish/
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

USE_KDELIBS_VER=2
INSTALLS_SHLIB=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	PATH=${WRKSRC}/auto-bin:$$PATH
MAKE_ENV+=	${CONFIGURE_ENV}

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin 
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor

.include <bsd.port.mk>
