PORTNAME=	Device-RAID-Poller
PORTVERSION=	0.2.0
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	RAID poller providing LibreNMS JSON app and Nagios style checks

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Error-Helper>=1.0.0:devel/p5-Error-Helper \
		p5-JSON>=2.97.001:converters/p5-JSON \
		p5-Module-List>=0.004:devel/p5-Module-List
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
