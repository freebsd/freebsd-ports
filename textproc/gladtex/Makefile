# New ports collection makefile for:	gladtex
# Date created:		2006-02-04
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	gladtex
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	textproc math www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A program to replace LaTeX formulas in HTML files with images

LICENSE=	GPLv2

LIB_DEPENDS=	gif.5:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		dvips:${PORTSDIR}/print/dvipsk-tetex

USE_PERL5=	yes

BINPATH=	${PREFIX}/bin
INCPATH=	-I${LOCALBASE}/include
LIBPATH=	-L${LOCALBASE}/lib

MAKE_ENV+=	BINPATH=${BINPATH} INCPATH="${INCPATH}" LIBPATH=${LIBPATH}

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
.endif

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_SCRIPT} ${PORTNAME} ${BINPATH}; \
	${INSTALL_PROGRAM} eqn2img ${BINPATH}
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/
.endif

.include <bsd.port.mk>
