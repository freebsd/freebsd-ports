# ex:ts=8
# Ports collection makefile for:	ploticus
# Date created:			Jan 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ploticus
PORTVERSION=	2.11
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://ploticus.sourceforge.net/download/
DISTNAME=	plsrc${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates plots and graphs from data

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ming.3:${PORTSDIR}/graphics/ming \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${DISTNAME}/src
CONFLICTS=	slffea-* swi-pl-*

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

.ifdef WITHOUT_X11
MAKE_ARGS+=	NOXFLAG=-DNOX11 XLIBS= XOBJ=
PKGNAMESUFFIX=	-nox11
.else
USE_XPM=	yes
.endif

MAN1=	pl.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pl ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../prefabs/* ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/../man/man1/${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
