# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	IO-Async-SSL
PORTVERSION=	0.19
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use SSL/TLS with IO::Async

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Future>=0.33:${PORTSDIR}/devel/p5-Future \
		p5-IO-Async>=0.66:${PORTSDIR}/devel/p5-IO-Async\
		p5-IO-Socket-SSL>=1.968:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	${LOCALBASE}/bin/socat:${PORTSDIR}/net/socat \
		p5-Test-Identity>=0:${PORTSDIR}/devel/p5-Test-Identity \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
