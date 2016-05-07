# $FreeBSD$

PORTNAME=	Amon2-Plugin-Web-MobileAgent
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of HTTP::MobileAgent plugin for Amon2

RUN_DEPENDS=	\
	p5-Amon2>=3.66:www/p5-Amon2 \
	ja-p5-Encode-JP-Mobile>=0.29:japanese/p5-Encode-JP-Mobile \
	p5-HTTP-MobileAgent>0:www/p5-HTTP-MobileAgent \
	p5-HTTP-MobileAgent-Plugin-Charset>0:www/p5-HTTP-MobileAgent-Plugin-Charset \
	ja-p5-Lingua-JA-Regular-Unicode>0:japanese/p5-Lingua-JA-Regular-Unicode
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Tiffany>0:textproc/p5-Tiffany \
	p5-Amon2-DBI>0:databases/p5-Amon2-DBI \
	p5-LWP-Protocol-PSGI>0:www/p5-LWP-Protocol-PSGI \
	p5-HTML-FillInForm-Lite>0:www/p5-HTML-FillInForm-Lite \
	p5-HTTP-Session>0:www/p5-HTTP-Session \
	p5-Plack-Middleware-ReverseProxy>0:www/p5-Plack-Middleware-ReverseProxy \
	p5-Test-WWW-Mechanize-PSGI>0:devel/p5-Test-WWW-Mechanize-PSGI \
	p5-DBD-SQLite>0:databases/p5-DBD-SQLite \
	p5-String-CamelCase>0:textproc/p5-String-CamelCase \
	p5-Module-Find>0:devel/p5-Module-Find

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
