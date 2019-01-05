# $FreeBSD$

PORTNAME=	Proc-ProcessTable-Colorizer
PORTVERSION=	0.2.0
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Colorized and enhanced version of ps

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Error-Helper>=1.0.0:devel/p5-Error-Helper \
		p5-Proc-ProcessTable>=0.53:devel/p5-Proc-ProcessTable \
		p5-Term-ANSIColor>=4.06:devel/p5-Term-ANSIColor \
		p5-Term-Size>=0:devel/p5-Term-Size \
		p5-Text-Table>=1.133:textproc/p5-Text-Table \
		p5-BSD-Process>=0.07:sysutils/p5-BSD-Process
TEST_DEPENDS=	p5-Test-Pod>=1.22:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.08:devel/p5-Test-Pod-Coverage

USES=		perl5

NO_ARCH=	yes
USE_PERL5=	configure

.include <bsd.port.mk>
