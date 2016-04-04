# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Scheduler
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Schedule events to run in a cron-like manner

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-DateTime-Event-Cron>=0:devel/p5-DateTime-Event-Cron \
		p5-Set-Scalar>=0:devel/p5-Set-Scalar \
		p5-YAML>=0:textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
