# Created by: Andrey Kuzmin <akuz84@gmail.com>
# $FreeBSD$

PORTNAME=	Schedule-Cron-Events
PORTVERSION=	1.95
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	akuz84@gmail.com
COMMENT=	Take a line from a crontab and find out when events will occur

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep
BUILD_DEPENDS=	p5-Set-Crontab>=0:devel/p5-Set-Crontab \
		p5-Time-Local>=0:devel/p5-Time-Local
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
