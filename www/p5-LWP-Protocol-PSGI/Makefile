# $FreeBSD$

PORTNAME=	LWP-Protocol-PSGI
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to override LWP HTTP/HTTPS backend with your PSGI app

RUN_DEPENDS=	\
	p5-Guard>0:${PORTSDIR}/devel/p5-Guard \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-libwww>=5:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-LWP-Protocol-https>0:${PORTSDIR}/www/p5-LWP-Protocol-https

PERL_CONFIGURE=	yes

MAN3=	LWP::Protocol::PSGI.3

.include <bsd.port.mk>
