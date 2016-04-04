# $FreeBSD$

PORTNAME=	WWW-Mechanize-Cached
PORTVERSION=	1.50
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to cache response to be polite

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

DEPRECATED=	Depends on expiring www/p5-HTTP-CookieMonster
EXPIRATION_DATE=	2016-04-15

RUN_DEPENDS=	\
	p5-Cache-Cache>=1.02:devel/p5-Cache-Cache \
	p5-Class-Load>0:devel/p5-Class-Load \
	p5-Data-Dump>0:devel/p5-Data-Dump \
	p5-Devel-SimpleTrace>0:devel/p5-Devel-SimpleTrace \
	p5-Find-Lib>0:devel/p5-Find-Lib \
	p5-Path-Class>0:devel/p5-Path-Class \
	p5-Moo>=1.004005:devel/p5-Moo \
	p5-MooX-Types-MooseLike>0:devel/p5-MooX-Types-MooseLike \
	p5-WWW-Mechanize>0:www/p5-WWW-Mechanize \
	p5-LWP-ConsoleLogger>0:www/p5-LWP-ConsoleLogger \
	p5-Storable>=2.21:devel/p5-Storable
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>0:devel/p5-Test-Warn

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
