# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-Filter-SAX1toSAX2
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert SAX1 events to SAX2

BUILD_DEPENDS=	p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0:textproc/p5-XML-SAX-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
