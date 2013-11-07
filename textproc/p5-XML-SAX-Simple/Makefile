# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-SAX-Simple
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SAX version of XML::Simple

BUILD_DEPENDS=	p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XML-Handler-Trees>=0:${PORTSDIR}/textproc/p5-XML-Handler-Trees
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
