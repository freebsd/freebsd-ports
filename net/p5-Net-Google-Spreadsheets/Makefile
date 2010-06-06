# New ports collection makefile for:	p5-Net-Google-Spreadsheets
# Date created:				23 March 2010
# Whom:					Gunter Wambaugh <gunter@six-two.net>
#
# $FreeBSD$
#

PORTNAME=	Net-Google-Spreadsheets
PORTVERSION=	0.11
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gunter@six-two.net
COMMENT=	A Perl module for using Google Spreadhseets API

BUILD_DEPENDS=	${SITE_PERL}/XML/Atom.pm:${PORTSDIR}/textproc/p5-XML-Atom \
		${SITE_PERL}/Net/Google/AuthSub.pm:${PORTSDIR}/net/p5-Net-Google-AuthSub \
		${SITE_PERL}/Net/Google/DataAPI.pm:${PORTSDIR}/net/p5-Net-Google-DataAPI \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/namespace/autoclean.pm:${PORTSDIR}/devel/p5-namespace-autoclean \
		${SITE_PERL}/Any/Moose.pm:${PORTSDIR}/devel/p5-Any-Moose \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/MockModule.pm:${PORTSDIR}/devel/p5-Test-MockModule \
		${SITE_PERL}/Test/MockObject.pm:${PORTSDIR}/devel/p5-Test-MockObject
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Google::Spreadsheets.3 \
		Net::Google::Spreadsheets::Cell.3 \
		Net::Google::Spreadsheets::Record.3 \
		Net::Google::Spreadsheets::Row.3 \
		Net::Google::Spreadsheets::Spreadsheet.3 \
		Net::Google::Spreadsheets::Table.3 \
		Net::Google::Spreadsheets::Worksheet.3

.include <bsd.port.mk>
