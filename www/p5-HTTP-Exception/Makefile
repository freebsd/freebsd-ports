# $FreeBSD$

PORTNAME=	HTTP-Exception
PORTVERSION=	0.04004
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to throw HTTP-Errors as (Exception::Class-) Exceptions

RUN_DEPENDS=	\
	p5-Exception-Class>=1.29:${PORTSDIR}/devel/p5-Exception-Class \
	p5-libwww>=5.817:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Exception>=0.29:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Test-NoWarnings>=1.04:${PORTSDIR}/devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
