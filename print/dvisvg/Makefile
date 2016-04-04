# Created by: ijliao
# $FreeBSD$

PORTNAME=	dvisvg
DISTVERSION=	0.7.1d
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	http://dvisvg.sourceforge.net/files/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Converter from DVI to SVG

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
USES=		ghostscript:run
USE_TEX=	base texmf texhash
ALL_TARGET=	# empty
# workaround for svgfonts.c not including kpathsea/c-auto.h
CFLAGS+=	-DHAVE_PROTOTYPES
MAKE_ARGS=	CC="${CC} ${CFLAGS}" TARGETDIR=${PREFIX} \
		LINC=${LOCALBASE}/include \
		LLIB=${LOCALBASE}/lib \
		BINDIR=${PREFIX}/bin \
		CNFDIR=${PREFIX}/${TEXMFDIR}/dvisvg \

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/share/texmf,${LOCALBASE}/${TEXMFDIR}," \
	    ${WRKSRC}/version.h

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dvisvg ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dvisvg.man \
	    ${STAGEDIR}${MAN1PREFIX}/man/man1/dvisvg.1
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDIR}/${PORTNAME}
.for file in dvisvg.map font2svg.enc font2svg.ps
	${INSTALL_DATA} ${WRKSRC}/${file} \
	    ${STAGEDIR}${PREFIX}/${TEXMFDIR}/${PORTNAME}
.endfor

.include <bsd.port.mk>
