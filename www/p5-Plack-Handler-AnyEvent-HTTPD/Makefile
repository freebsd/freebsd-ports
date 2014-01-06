# $FreeBSD$

PORTNAME=	Plack-Handler-AnyEvent-HTTPD
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Plack handler to run PSGI apps on AnyEvent::HTTPD

RUN_DEPENDS=	\
	p5-AnyEvent-HTTPD>0:${PORTSDIR}/www/p5-AnyEvent-HTTPD \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Plack>=0.9903:${PORTSDIR}/www/p5-Plack \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
