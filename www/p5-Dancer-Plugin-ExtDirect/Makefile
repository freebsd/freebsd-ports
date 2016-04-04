# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-ExtDirect
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Dancer plugin for implementing ExtDirect APIs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>=1.2001:www/p5-Dancer \
		p5-JSON>=0:converters/p5-JSON
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
