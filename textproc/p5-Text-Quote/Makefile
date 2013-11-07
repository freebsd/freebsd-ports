# Created by: ijliao
# $FreeBSD$

PORTNAME=	Text-Quote
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Quotes strings as required for perl to eval them back correctly

BUILD_DEPENDS=	p5-Carp-Assert>=0.13:${PORTSDIR}/devel/p5-Carp-Assert
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
