# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CatalystX-LeakChecker
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Debug memory leaks in Catalyst applications

BUILD_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Devel-Cycle>0:${PORTSDIR}/devel/p5-Devel-Cycle \
		p5-PadWalker>0:${PORTSDIR}/devel/p5-PadWalker
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
