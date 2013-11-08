# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	WebService-Linode
PORTVERSION=	0.15
CATEGORIES=	www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Interface to the Linode.com API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Mozilla-CA>=0:${PORTSDIR}/www/p5-Mozilla-CA \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
