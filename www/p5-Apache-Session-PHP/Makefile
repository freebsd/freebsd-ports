# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	Apache-Session-PHP
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Glue Apache::Session with PHP::Session

BUILD_DEPENDS=	p5-PHP-Session>=0:${PORTSDIR}/www/p5-PHP-Session \
		p5-Apache-Session>=0:${PORTSDIR}/www/p5-Apache-Session 
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
