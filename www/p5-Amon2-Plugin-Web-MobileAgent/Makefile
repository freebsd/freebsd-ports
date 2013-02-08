# $FreeBSD$

PORTNAME=	Amon2-Plugin-Web-MobileAgent
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of HTTP::MobileAgent plugin for Amon2

RUN_DEPENDS=	\
	p5-Amon2>=3.66:${PORTSDIR}/www/p5-Amon2 \
	ja-p5-Encode-JP-Mobile>=0.29:${PORTSDIR}/japanese/p5-Encode-JP-Mobile \
	p5-HTTP-MobileAgent>0:${PORTSDIR}/www/p5-HTTP-MobileAgent \
	p5-HTTP-MobileAgent-Plugin-Charset>0:${PORTSDIR}/www/p5-HTTP-MobileAgent-Plugin-Charset \
	p5-Lingua-JA-Regular-Unicode>0:${PORTSDIR}/japanese/p5-Lingua-JA-Regular-Unicode
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Tiffany>0:${PORTSDIR}/textproc/p5-Tiffany \
	p5-Amon2-DBI>0:${PORTSDIR}/databases/p5-Amon2-DBI \
	p5-LWP-Protocol-PSGI>0:${PORTSDIR}/www/p5-LWP-Protocol-PSGI \
	p5-HTML-FillInForm-Lite>0:${PORTSDIR}/www/p5-HTML-FillInForm-Lite \
	p5-HTTP-Session>0:${PORTSDIR}/www/p5-HTTP-Session \
	p5-Plack-Middleware-ReverseProxy>0:${PORTSDIR}/www/p5-Plack-Middleware-ReverseProxy \
	p5-Test-WWW-Mechanize-PSGI>0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-PSGI \
	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-String-CamelCase>0:${PORTSDIR}/textproc/p5-String-CamelCase \
	p5-Module-Find>0:${PORTSDIR}/devel/p5-Module-Find

PERL_MODBUILD=	yes

MAN3=	Amon2::Plugin::Web::MobileAgent.3 \
	Amon2::Plugin::Web::MobileCharset.3 \
	Amon2::Setup::Flavor::MobileJP.3

.include <bsd.port.mk>
