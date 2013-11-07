# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Pod-Abstract
PORTVERSION=	0.20
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstract document tree for Perl POD documents

BUILD_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
