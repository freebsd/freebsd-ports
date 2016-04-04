# $FreeBSD$

PORTNAME=	HTTP-Exception
PORTVERSION=	0.04006
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to throw HTTP-Errors as (Exception::Class-) Exceptions

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Exception-Class>=1.29:devel/p5-Exception-Class \
	p5-HTTP-Message>=5.817:www/p5-HTTP-Message
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Exception>=0.29:devel/p5-Test-Exception \
	p5-Test-NoWarnings>=1.04:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
