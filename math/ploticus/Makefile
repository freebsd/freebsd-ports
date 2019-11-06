# Created by: ijliao
# $FreeBSD$

PORTNAME=	ploticus
PORTVERSION=	2.40
PORTREVISION=	10
CATEGORIES=	math
MASTER_SITES=	SF
DISTNAME=	pl${PORTVERSION:S/.//}src

MAINTAINER?=	linimon@FreeBSD.org
COMMENT?=	Generates plots and graphs from data

LIB_DEPENDS=	libgd.so:graphics/gd \
		libming.so:graphics/ming \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		jpeg
BUILD_WRKSRC=	${WRKSRC}/src

FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config

MAKE_ARGS=	CC="${CC}" FLAGS="${CFLAGS}" \
		LOCALEOBJ="localef.o" LOCALE_FLAG="-DLOCALE" \
		MING="-L${LOCALBASE}/lib -lming" \
		MINGH="-I${LOCALBASE}/include/ming" NOSWFFLAG="" \
		GD18LIBS="`${FREETYPE_CONFIG} --libs` \
			-L${LOCALBASE}/lib -lgd -lpng -lz -ljpeg" \
		GD18H="`${FREETYPE_CONFIG} --cflags` \
			-L${LOCALBASE}/include" \
		GDFREETYPE="-DGDFREETYPE" PREFABS_DIR="${DATADIR}"
ALL_TARGET=	plgd18

.ifdef (WITHOUT_X11)
MAKE_ARGS+=	NOX11=-DNOX11 XLIBS= XOBJ=
PKGNAMESUFFIX=	-nox11
.else
USES+=		xorg
USE_XORG=	xpm
.endif

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${BUILD_WRKSRC}/Makefile ${BUILD_WRKSRC}/mkapi

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/pl ${STAGEDIR}${PREFIX}/bin/ploticus
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/prefabs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/man/man1/pl.1 ${STAGEDIR}${MANPREFIX}/man/man1/ploticus.1
	${INSTALL_MAN} ${WRKSRC}/man/man3/libploticus.3 ${STAGEDIR}${MANPREFIX}/man/man3
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/pltestsuite && ${FIND} . \! -name "*.orig" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
