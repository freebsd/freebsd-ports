# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	XML-RSS-Liberal
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML::RSS With A Liberal Parser

BUILD_DEPENDS=	p5-XML-Liberal>=0:textproc/p5-XML-Liberal	\
		p5-XML-RSS-LibXML>=0:textproc/p5-XML-RSS-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
