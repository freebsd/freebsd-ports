# $FreeBSD$

PORTNAME=	POE-Component-Server-SimpleHTTP
PORTVERSION=	2.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to serve HTTP requests in POE

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.81:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>0:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-MooseX-POE>=0.205:${PORTSDIR}/devel/p5-MooseX-POE \
		p5-POE>=1.0000:${PORTSDIR}/devel/p5-POE \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-POE-Filter-HTTP-Parser>=1.06:${PORTSDIR}/www/p5-POE-Filter-HTTP-Parser \
		p5-Test-POE-Client-TCP>0:${PORTSDIR}/devel/p5-Test-POE-Client-TCP

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	SSL
SSL_DESC=	SSL support (POE::Component::SSLify)
OPTIONS_DEFAULT=	SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
BUILD_DEPENDS+=	p5-POE-Component-SSLify>=0.04:${PORTSDIR}/security/p5-POE-Component-SSLify
.endif

.include <bsd.port.mk>
