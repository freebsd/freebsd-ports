# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer-Logger-Log4perl
PORTVERSION=	0.8.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Dancer logging adapter for Log::Log4perl

LICENSE=	ART20

BUILD_DEPENDS=	p5-Dancer>=1.2001:${PORTSDIR}/www/p5-Dancer \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
