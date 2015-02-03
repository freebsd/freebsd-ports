# Created by: Dima Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	fltk
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://fltk.org/pub/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform C++ graphical user interface toolkit

LICENSE=	LGPL20

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

USES=		pkgconfig
USE_XORG=	xft
USE_GL=		glu
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${WRKSRC}/src -L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	prefix="${PREFIX}" ; plength=$$(($${#prefix}+10)) ; \
	${REINPLACE_CMD} -e "\|/etc/fltk|{s||${PREFIX}&|;s|10|$${plength}|;}" \
	${WRKSRC}/src/Fl_Preferences.cxx

.include <bsd.port.mk>
