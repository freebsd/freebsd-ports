# $FreeBSD$

PORTNAME=	RT-Client-REST
PORTVERSION=	0.44
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl modules designed to talk to RT installation using REST protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DateTime-Format-DateParse>0:${PORTSDIR}/devel/p5-DateTime-Format-DateParse \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
