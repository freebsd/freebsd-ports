# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Jemplate
PORTVERSION=	0.270
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-
DISTNAME=	Jemplate-0.27

MAINTAINER=	lth@FreeBSD.org
COMMENT=	JavaScript Templating with Template Toolkit

RUN_DEPENDS=	p5-File-Find-Rule>=0.30:devel/p5-File-Find-Rule \
		p5-Template-Toolkit>=2.19:www/p5-Template-Toolkit
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
