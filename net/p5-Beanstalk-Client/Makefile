# $FreeBSD$

PORTNAME=	Beanstalk-Client
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GBARR
PKGNAMEPREFIX=	p5-

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Perl API for beanstalkd, a distributed queue daemon

BUILD_DEPENDS=	p5-YAML-Syck>=0:textproc/p5-YAML-Syck \
				p5-Class-Accessor>=0:devel/p5-Class-Accessor \
				p5-Error>=0:lang/p5-Error
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
