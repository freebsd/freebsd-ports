# New ports collection makefile for:   	fltk
# Date created:				11 February 1999
# Whom:                			Dima Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION=	1.3.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=	fltk/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Cross-platform C++ graphical user interface toolkit

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_LDCONFIG=	yes
USE_XORG=	xft
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-threads \
		--enable-shared \
		--enable-xft
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${WRKSRC}/src -L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=	fltk-config.1 fluid.1
MAN3=	fltk.3

post-patch:
	${REINPLACE_CMD} -e '30s/test //' ${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
PORTDOCS=	*
post-install:
	cd ${WRKSRC}/documentation && ${MAKE} docinstall
	cd ${WRKSRC}/test && ${MAKE} install
.endif

.include <bsd.port.mk>
