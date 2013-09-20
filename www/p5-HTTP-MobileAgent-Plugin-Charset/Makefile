# $FreeBSD$

PORTNAME=	HTTP-MobileAgent-Plugin-Charset
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to plugin Encode::JP::Mobile for HTTP::MobileAgent

RUN_DEPENDS=	\
	p5-HTTP-MobileAgent>=0.26:${PORTSDIR}/www/p5-HTTP-MobileAgent
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	HTTP::MobileAgent::Plugin::Charset.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
