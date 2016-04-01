# Created by: Andrew Thompson <thompsa@freebsd.org>
# $FreeBSD$

PORTNAME=	Nagios-Plugin-Beanstalk
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GBARR
PKGNAMEPREFIX=	p5-

MAINTAINER=	thompsa@FreeBSD.org
COMMENT=	Module to check beanstalkd via nagios

BUILD_DEPENDS=	p5-Nagios-Plugin>=0:net-mgmt/p5-Nagios-Plugin \
		p5-Beanstalk-Client>=0:net/p5-Beanstalk-Client

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL} ${WRKSRC}/check_beanstalkd ${STAGEDIR}${PREFIX}/libexec/nagios/check_beanstalkd

.include <bsd.port.mk>
