# New ports collection makefile for:	xfe
# Date created:				Sun, Jul 13 2003
# Whom:					ptiJo
#
# $FreeBSD$
#

PORTNAME=	xfe
PORTVERSION=	1.19.2
PORTREVISION=	4
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast MS-Explorer like filemanager for X

LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16 \
		png.5:${PORTSDIR}/graphics/png

USE_XORG=	xft
USE_GNOME=	gnomehack gnometarget
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		xfe.1 xfi.1 xfp.1 xfv.1 xfw.1

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS=""|#CXXFLAGS=""|g ; \
		 s|-O2 ||g ; \
		 /if test/s|==|=|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|/usr/share/xfe|${DATADIR}|' \
		${WRKSRC}/src/XFileExplorer.cpp ${WRKSRC}/src/help.h
	@${REINPLACE_CMD} 's|/usr/local/share/xfe|${DATADIR}|' \
		${WRKSRC}/src/xfedefs.h

.include <bsd.port.mk>
