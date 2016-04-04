# $FreeBSD$

PORTNAME=	Dancer-Plugin-ValidationClass
PORTVERSION=	0.120490
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for centralized input validation for Dancer

RUN_DEPENDS=	\
	p5-Dancer>0:www/p5-Dancer \
	p5-Validation-Class>0:devel/p5-Validation-Class
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
