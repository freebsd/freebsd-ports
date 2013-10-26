# $FreeBSD$

PORTNAME=	HTTP-Engine
PORTVERSION=	0.03005
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for HTTP Server Engine Drivers

BUILD_DEPENDS=	\
	p5-Any-Moose>=0.13:${PORTSDIR}/devel/p5-Any-Moose \
	p5-CGI-Simple>=1.103:${PORTSDIR}/www/p5-CGI-Simple \
	p5-Filter>0:${PORTSDIR}/devel/p5-Filter \
	p5-HTTP-Body>=1.05:${PORTSDIR}/www/p5-HTTP-Body \
	p5-HTTP-Headers-Fast>=0.11:${PORTSDIR}/www/p5-HTTP-Headers-Fast \
	p5-HTTP-Server-Simple>=0.35:${PORTSDIR}/www/p5-HTTP-Server-Simple \
	p5-Mouse>=0.62:${PORTSDIR}/devel/p5-Mouse \
	p5-URI>=1.36:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	\
	p5-HTTP-Request-AsCGI>0:${PORTSDIR}/www/p5-HTTP-Request-AsCGI \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML \
	p5-IO-stringy>0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-MouseX-Types>=0.05:${PORTSDIR}/devel/p5-MouseX-Types

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
