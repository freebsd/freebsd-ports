# Ports collection makefile for:  pear-Spreadsheet_Excel_Writer
# Date created:			  16 March 2004
# Whom:				  Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet_Excel_Writer
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	textproc www pear

MAINTAINER=	pav@FreeBSD.org
COMMENT=	PEAR class for writing Microsoft Excel files

BUILD_DEPENDS=	${PEARDIR}/OLE/OLE.php:${PORTSDIR}/devel/pear-OLE \
		${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Spreadsheet/Excel
FILES=		Writer.php Writer/BIFFwriter.php Writer/Format.php Writer/Parser.php \
		Writer/Validator.php Writer/Workbook.php Writer/Worksheet.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
