# $FreeBSD$

PORTNAME=	Furl
PORTVERSION=	2.19
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of lightning-fast URL fetcher

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-HTTP-Parser-XS>=0.11:${PORTSDIR}/www/p5-HTTP-Parser-XS \
	p5-Mozilla-CA>0:${PORTSDIR}/www/p5-Mozilla-CA
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-TCP>=0:${PORTSDIR}/devel/p5-Test-TCP \
		p5-Plack>0:${PORTSDIR}/www/p5-Plack \
		p5-HTTP-Proxy>0:${PORTSDIR}/www/p5-HTTP-Proxy \
		p5-Plack-Middleware-Deflater>0:${PORTSDIR}/www/p5-Plack-Middleware-Deflater \
		p5-IO-Callback>0:${PORTSDIR}/devel/p5-IO-Callback \
		p5-Starlet>0:${PORTSDIR}/www/p5-Starlet \
		p5-Net-IDN-Encode>0:${PORTSDIR}/textproc/p5-Net-IDN-Encode

USES=	perl5
USE_PERL5=	modbuild

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
