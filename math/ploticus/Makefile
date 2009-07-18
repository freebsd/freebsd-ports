# ex:ts=8
# Ports collection makefile for:	ploticus
# Date created:			Jan 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ploticus
PORTVERSION=	2.40
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF
DISTNAME=	pl${PORTVERSION:S/.//}src

MAINTAINER?=	linimon@FreeBSD.org
COMMENT?=	Generates plots and graphs from data

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		ming.4:${PORTSDIR}/graphics/ming \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

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
USE_XORG=	xpm
.endif

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		ploticus.1
MAN3=		libploticus.3
MANCOMPRESSED=	no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${BUILD_WRKSRC}/Makefile ${BUILD_WRKSRC}/mkapi

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/pl ${PREFIX}/bin/ploticus
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/prefabs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.if !defined(NO_INSTALL_MANPAGES)
	# pl.1 conflicts with lang/TenDRA
	${INSTALL_MAN} ${WRKSRC}/man/man1/pl.1 ${MANPREFIX}/man/man1/ploticus.1
	${INSTALL_MAN} ${WRKSRC}/man/man3/${MAN3} ${MANPREFIX}/man/man3
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/pltestsuite && ${FIND} . \! -name "*.orig" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
