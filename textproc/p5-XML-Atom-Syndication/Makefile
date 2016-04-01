# Created by: arved
# $FreeBSD$

PORTNAME=	XML-Atom-Syndication
PORTVERSION=	0.94.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple lightweight client for consuming Atom syndication feeds

BUILD_DEPENDS=	p5-Class-ErrorHandler>=0:devel/p5-Class-ErrorHandler \
		p5-XML-Elemental>=2:textproc/p5-XML-Elemental \
		p5-XML-Writer>=0.6:textproc/p5-XML-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
