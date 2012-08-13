# New ports collection makefile for:	xfe
# Date created:				Sun, Jul 13 2003
# Whom:					ptiJo
#
# $FreeBSD$
#

PORTNAME=	xfe
PORTVERSION=	1.33
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fast MS-Explorer like filemanager for X

LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16

USE_XORG=	xft
USE_GNOME=	gnomehack intltool
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		xfe.1 xfi.1 xfp.1 xfv.1 xfw.1

post-patch:
	@${REINPLACE_CMD} 's|/usr/local/share/xfe|${DATADIR}|g' \
		${WRKSRC}/src/XFileExplorer.cpp \
		${WRKSRC}/src/help.h \
		${WRKSRC}/src/xfedefs.h
	@${REINPLACE_CMD} 's/unsigned FXchar/FXuchar/' \
		${WRKSRC}/src/xfeutils.cpp

.include <bsd.port.mk>
