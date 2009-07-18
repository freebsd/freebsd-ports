# New ports collection makefile for:	ascpu
# Date created:         18 February 1999
# Whom:                 Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	ascpu
PORTVERSION=	1.11
PORTREVISION=	3
CATEGORIES=	sysutils afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/ascpu/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	CPU statistics monitor utility for XFree86

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xpm-includes=${LOCALBASE}/include --with-xpm-library=${LOCALBASE}/lib
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	EXTRA_LIBRARIES="-L${LOCALBASE}/lib"

MAN1=		ascpu.1
PLIST_FILES=	bin/ascpu

do-install:
	@ ${INSTALL_MAN} ${WRKSRC}/ascpu.man ${PREFIX}/man/man1/ascpu.1
	@ ${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g kmem -m 2755 ${WRKSRC}/ascpu ${PREFIX}/bin

.include <bsd.port.mk>
