# $FreeBSD$

PORTNAME=	Starman
PORTVERSION=	0.4008
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for high-performance preforking PSGI web server

RUN_DEPENDS=	\
	p5-Data-Dump>0:${PORTSDIR}/devel/p5-Data-Dump \
	p5-HTTP-Parser-XS>0:${PORTSDIR}/www/p5-HTTP-Parser-XS \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Net-Server>=2.007:${PORTSDIR}/net/p5-Net-Server \
	p5-Plack>=0.9971:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-TCP>=2.00:${PORTSDIR}/devel/p5-Test-TCP
# TODO: maybe need p5-libwww

USES=	perl5
USE_PERL5=	modbuildtiny
USE_RC_SUBR=	starman

.include <bsd.port.mk>
