# $FreeBSD$

PORTNAME=	Twiggy-TLS
PORTVERSION=	0.0018
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:UNDEF
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to extend Twiggy supporting TLS

RUN_DEPENDS=	\
	p5-Twiggy>=0.1010:${PORTSDIR}/www/p5-Twiggy \
	p5-Plack>=0.99:${PORTSDIR}/www/p5-Plack \
	p5-IO-Socket-SSL>=1.62:${PORTSDIR}/security/p5-IO-Socket-SSL
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP \
	p5-libwww>=6.00:${PORTSDIR}/www/p5-libwww \
	p5-LWP-Protocol-https>=6.02:${PORTSDIR}/www/p5-LWP-Protocol-https

PERL_CONFIGURE=	yes

MAN3=	Twiggy::TLS.3 \
	Twiggy::TLS::Info.3

.include <bsd.port.mk>
