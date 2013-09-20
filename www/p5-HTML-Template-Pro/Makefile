# $FreeBSD$

PORTNAME=	HTML-Template-Pro
PORTVERSION=	0.9510
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to use HTML Templates from CGI scripts

RUN_DEPENDS=	\
	p5-JSON>=2:${PORTSDIR}/converters/p5-JSON
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	HTML::Template::PerlInterface.3 \
	HTML::Template::Pro.3 \
	HTML::Template::SYNTAX.3

NO_STAGE=	yes
.include <bsd.port.mk>
