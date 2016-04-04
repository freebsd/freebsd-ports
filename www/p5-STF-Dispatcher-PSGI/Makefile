# $FreeBSD$

PORTNAME=	STF-Dispatcher-PSGI
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for pluggable STF dispatcher interface

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:devel/p5-Class-Accessor-Lite \
	p5-HTTP-Date>0:www/p5-HTTP-Date \
	p5-Plack>0:www/p5-Plack \
	p5-Plack-Middleware-Header>0:www/p5-Plack-Middleware-Header
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Net-STF-Client>0:www/p5-Net-STF-Client \
	p5-Test-TCP>0:devel/p5-Test-TCP

USES=	perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
