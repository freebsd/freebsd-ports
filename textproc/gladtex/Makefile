# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	gladtex
PORTVERSION=	1.3
PORTREVISION=	0
CATEGORIES=	textproc math www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A program to replace LaTeX formulas in HTML files with images

LICENSE=	GPLv2

LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
		libpng15.so:${PORTSDIR}/graphics/png

USE_TEX=	latex dvipsk
BINPATH=	${PREFIX}/bin
INCPATH=	"-I${LOCALBASE}/include"
LIBPATH=	"-L${LOCALBASE}/lib"

MAKE_ENV+=	BINPATH=${BINPATH} INCPATH="${INCPATH}" LIBPATH="${LIBPATH}"

USES=		perl5

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${BINPATH}; \
	${INSTALL_PROGRAM} ${WRKSRC}/eqn2img ${STAGEDIR}${BINPATH}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
