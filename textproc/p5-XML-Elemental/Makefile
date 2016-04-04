# Created by: arved
# $FreeBSD$

PORTNAME=	XML-Elemental
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic classes for simplistic and perlish handling of XML data

BUILD_DEPENDS=	p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-Task-Weaken>=1.02:devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
