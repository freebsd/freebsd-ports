# $FreeBSD$

PORTNAME=	Amon2
PORTVERSION=	3.85
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for/to lightweight web application framework

RUN_DEPENDS=	\
	p5-Plack>=0.9982:${PORTSDIR}/www/p5-Plack \
	p5-Plack-Middleware-Session>0:${PORTSDIR}/www/p5-Plack-Middleware-Session \
	p5-Router-Simple>=0.14:${PORTSDIR}/www/p5-Router-Simple \
	p5-Router-Simple-Sinatraish>=0.02:${PORTSDIR}/www/p5-Router-Simple-Sinatraish \
	p5-Text-Xslate>=1.6001:${PORTSDIR}/textproc/p5-Text-Xslate \
	p5-Try-Tiny>=0.06:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-URI>=1.54:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires

USES=	perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
