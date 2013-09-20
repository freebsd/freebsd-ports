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

LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png

USE_TEX=	latex dvipsk
BINPATH=	${PREFIX}/bin
INCPATH=	"-I${LOCALBASE}/include"
LIBPATH=	"-L${LOCALBASE}/lib"

MAKE_ENV+=	BINPATH=${BINPATH} INCPATH="${INCPATH}" LIBPATH="${LIBPATH}"

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
.endif

USES=		perl5

NO_STAGE=	yes
do-install:
	@cd ${WRKSRC}; \
	${INSTALL_SCRIPT} ${PORTNAME} ${BINPATH}; \
	${INSTALL_PROGRAM} eqn2img ${BINPATH}
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/
.endif

.include <bsd.port.mk>
