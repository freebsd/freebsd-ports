# $FreeBSD$

PORTNAME=	LWP-Protocol-PSGI
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to override LWP HTTP/HTTPS backend with your PSGI app

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Guard>0:devel/p5-Guard \
	p5-Plack>0:www/p5-Plack \
	p5-libwww>=5:www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https

USES=	perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	YES

.include <bsd.port.mk>
