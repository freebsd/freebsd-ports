# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-Prototype
PORTVERSION=	0.9054
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Create a CGI application by subclassing

COMMON_DEPENDS=	p5-Class-Prototyped>0:devel/p5-Class-Prototyped \
		p5-Template-Toolkit>0:www/p5-Template-Toolkit
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
