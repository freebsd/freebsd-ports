# ex:ts=8
# New ports collection makefile for:	pdftohtml
# Date created:			1 Jun 2001
# Whom:				Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	pdftohtml
PORTVERSION=	0.36
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	A command-line tool for converting pdf-files into html

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

RUN_DEPENDS=	${LOCALBASE}/bin/gs:${PORTSDIR}/${GSPORT}

PLIST_FILES=	bin/pdftohtml
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_REINPLACE=	yes

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

pre-patch:
.for file in goo/Makefile xpdf/Makefile
	${REINPLACE_CMD} -e "s|-O2||; s|-g||" ${WRKSRC}/${file}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/pdftohtml ${PREFIX}/bin

.include <bsd.port.mk>
