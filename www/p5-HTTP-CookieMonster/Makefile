# $FreeBSD$

PORTNAME=	HTTP-CookieMonster
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to read/write access to HTTP::Cookies jar

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BROKEN=		bogus depends, p5-URI is not provided by net/p5-Net
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-04-15

RUN_DEPENDS=	\
	p5-HTTP-Cookies>0:www/p5-HTTP-Cookies \
	p5-Moo>=1.000003:devel/p5-Moo \
	p5-Safe-Isa>0:devel/p5-Safe-Isa \
	p5-Sub-Exporter>0:devel/p5-Sub-Exporter \
	p5-URI>0:net/p5-Net
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
