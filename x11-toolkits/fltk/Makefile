# Created by: Dima Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	fltk
PORTVERSION=	1.3.3
DISTVERSIONSUFFIX=	-source
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://fltk.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform C++ graphical user interface toolkit

LICENSE=	LGPL20

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		pkgconfig
USE_XORG=	xft
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads \
		--enable-shared \
		--enable-xft
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/.SILENT/s|^|#| ; \
		 /echo /s|^|#|' ${WRKSRC}/makeinclude.in
	@${REINPLACE_CMD} -e \
		'/cat[13]/s|^|#|' ${WRKSRC}/documentation/Makefile
	@${REINPLACE_CMD} -e \
		's|"/etc/fltk/"|"${ETCDIR}/"|' ${WRKSRC}/src/Fl_Preferences.cxx

post-install:
	@(cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fluid
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfltk*.so.[0-9]*

.include <bsd.port.mk>
