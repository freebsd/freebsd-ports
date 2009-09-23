# New ports collection makefile for:	LaTeX-Table
# Date created:				4th June, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	LaTeX-Table
PORTVERSION=	1.0.0
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl extension for the automatic generation of LaTeX tables

BUILD_DEPENDS=	p5-Test-NoWarnings>=0.084:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Moose-Policy>=0:${PORTSDIR}/devel/p5-Moose-Policy \
		p5-version>=0:${PORTSDIR}/devel/p5-version \
		p5-LaTeX-Encode>=0:${PORTSDIR}/textproc/p5-LaTeX-Encode \
		p5-LaTeX-Driver>=0:${PORTSDIR}/textproc/p5-LaTeX-Driver \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-autodie>=2.06:${PORTSDIR}/devel/p5-autodie \
		p5-Number-Format>=0:${PORTSDIR}/textproc/p5-Number-Format
RUN_DEPENDS=	p5-Test-NoWarnings>=0.084:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Moose-Policy>=0:${PORTSDIR}/devel/p5-Moose-Policy \
		p5-version>=0:${PORTSDIR}/devel/p5-version \
		p5-LaTeX-Encode>=0:${PORTSDIR}/textproc/p5-LaTeX-Encode \
		p5-LaTeX-Driver>=0:${PORTSDIR}/textproc/p5-LaTeX-Driver \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-autodie>=2.06:${PORTSDIR}/devel/p5-autodie \
		p5-Number-Format>=0:${PORTSDIR}/textproc/p5-Number-Format \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly

PERL_CONFIGURE=	yes
PERL_MODBUILD=	yes

MAN1=	csv2pdf.1 ltpretty.1
MAN3=	LaTeX::Table::Types::Ctable.3 \
	LaTeX::Table::Types::TypeI.3 \
	LaTeX::Table::Themes::Booktabs.3 \
	LaTeX::Table::Themes::Classic.3 \
	LaTeX::Table::Themes::Beamer.3 \
	LaTeX::Table::Themes::ThemeI.3 \
	LaTeX::Table::Themes::Modern.3 \
	LaTeX::Table.3 \
	LaTeX::Table::Types::Longtable.3 \
	LaTeX::Table::Types::Xtab.3 \
	LaTeX::Table::Types::Std.3

.include <bsd.port.mk>
