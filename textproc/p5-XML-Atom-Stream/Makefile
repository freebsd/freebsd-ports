# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Atom-Stream
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client interface for AtomStream

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-XML-SAX>=0.12:textproc/p5-XML-SAX \
		p5-XML-Handler-Trees>=0.02:textproc/p5-XML-Handler-Trees \
		p5-XML-Atom>=0.20:textproc/p5-XML-Atom \
		p5-XML-LibXML>=1.59:textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
