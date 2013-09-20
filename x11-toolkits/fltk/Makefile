# Created by: Dima Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	fltk
PORTVERSION=	1.3.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://fltk.org/pub/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Cross-platform C++ graphical user interface toolkit

LICENSE=	LGPL20

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_LDCONFIG=	yes
USE_XORG=	xft
USE_GL=		glu
USES=		pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-threads \
		--enable-shared \
		--enable-xft

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${WRKSRC}/src -L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

MAN1=	fltk-config.1 fluid.1
MAN3=	fltk.3

NO_STAGE=	yes
post-patch:
	prefix="${PREFIX}" ; plength=$$(($${#prefix}+10)) ; \
	${REINPLACE_CMD} -e "\|/etc/fltk|{s||${PREFIX}&|;s|10|$${plength}|;}" \
	${WRKSRC}/src/Fl_Preferences.cxx

.if !defined(NOPORTDOCS)
post-install:
	cd ${WRKSRC}/documentation && ${MAKE} docinstall
	cd ${WRKSRC}/test && ${MAKE} install
.endif

.include <bsd.port.mk>
