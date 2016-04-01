# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	ZConf-Cron
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Handles storing cron tabs in ZConf

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime-Event-Cron>=0:devel/p5-DateTime-Event-Cron \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-ZConf-GUI>=0:devel/p5-ZConf-GUI \
		p5-ZConf>=0:net/p5-ZConf
RUN_DEPENDS:=	p5-DateTime-Event-Cron>=0:devel/p5-DateTime-Event-Cron \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-ZConf-GUI>=0:devel/p5-ZConf-GUI \
		p5-ZConf>=0:net/p5-ZConf

NO_ARCH=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	bin/gzccrontab bin/zccrontab bin/zccron
USE_PERL5=	configure

.include <bsd.port.mk>
