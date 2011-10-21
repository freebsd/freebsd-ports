# New ports collection makefile for:	p5-Excel-Writer-XLSX
# Date created:		2011-10-02
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Excel-Writer-XLSX
PORTVERSION=	0.32
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create a new file in the Excel 2007+ XLSX format

BUILD_DEPENDS=	p5-Archive-Zip>=1.30:${PORTSDIR}/archivers/p5-Archive-Zip
RUN_DEPENDS=	p5-Archive-Zip>=1.30:${PORTSDIR}/archivers/p5-Archive-Zip

PERL_CONFIGURE=	yes

MAN3=		Excel::Writer::XLSX.3 \
		Excel::Writer::XLSX::Chart.3 \
		Excel::Writer::XLSX::Chart::Area.3 \
		Excel::Writer::XLSX::Chart::Bar.3 \
		Excel::Writer::XLSX::Chart::Column.3 \
		Excel::Writer::XLSX::Chart::Line.3 \
		Excel::Writer::XLSX::Chart::Pie.3 \
		Excel::Writer::XLSX::Chart::Scatter.3 \
		Excel::Writer::XLSX::Chart::Stock.3 \
		Excel::Writer::XLSX::Chartsheet.3 \
		Excel::Writer::XLSX::Drawing.3 \
		Excel::Writer::XLSX::Examples.3 \
		Excel::Writer::XLSX::Format.3 \
		Excel::Writer::XLSX::Package::App.3 \
		Excel::Writer::XLSX::Package::Comments.3 \
		Excel::Writer::XLSX::Package::ContentTypes.3 \
		Excel::Writer::XLSX::Package::Core.3 \
		Excel::Writer::XLSX::Package::Packager.3 \
		Excel::Writer::XLSX::Package::Relationships.3 \
		Excel::Writer::XLSX::Package::SharedStrings.3 \
		Excel::Writer::XLSX::Package::Styles.3 \
		Excel::Writer::XLSX::Package::Theme.3 \
		Excel::Writer::XLSX::Package::VML.3 \
		Excel::Writer::XLSX::Package::XMLwriter.3 \
		Excel::Writer::XLSX::Package::XMLwriterSimple.3 \
		Excel::Writer::XLSX::Utility.3 \
		Excel::Writer::XLSX::Workbook.3 \
		Excel::Writer::XLSX::Worksheet.3

.include <bsd.port.mk>
