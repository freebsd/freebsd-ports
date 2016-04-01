# $FreeBSD$

PORTNAME=	Starman
PORTVERSION=	0.4014
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for high-performance preforking PSGI web server

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Data-Dump>0:devel/p5-Data-Dump \
	p5-HTTP-Parser-XS>0:www/p5-HTTP-Parser-XS \
	p5-Net-Server>=2.007:net/p5-Net-Server \
	p5-Plack>=0.9971:www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Test-TCP>=2.00:devel/p5-Test-TCP
# TODO: maybe need p5-libwww

USES=	perl5
USE_PERL5=	modbuildtiny
USE_RC_SUBR=	starman
NO_ARCH=	YES

.include <bsd.port.mk>
