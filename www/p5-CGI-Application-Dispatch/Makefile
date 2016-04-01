# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Dispatch
PORTVERSION=	3.12
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dispatch requests to CGI::Application based objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>=4.50:www/p5-CGI-Application \
		p5-CGI-PSGI>=0:www/p5-CGI-PSGI \
		p5-Exception-Class>=1.20:devel/p5-Exception-Class \
		p5-HTTP-Exception>=0:www/p5-HTTP-Exception \
		p5-Plack>=0.9956:www/p5-Plack \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-LongString>=0:devel/p5-Test-LongString

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
