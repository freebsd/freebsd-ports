# Created by: lbr@FreeBSD.org
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Cache
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible caching support for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.8000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-WWW-Mechanize-Catalyst>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst

USES=		perl5
USE_PERL5=	configure patch

post-patch:
	@${PERL} -i.bak -ne 'print unless m,ok|Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
