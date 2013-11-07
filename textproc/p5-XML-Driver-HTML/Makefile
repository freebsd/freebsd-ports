# Created by: Dmitry Morozovsky <marck@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Driver-HTML
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl SAX Driver for non wellformed HTML

BUILD_DEPENDS=	p5-XML-TreeBuilder>=0:${PORTSDIR}/textproc/p5-XML-TreeBuilder \
		p5-XML-Handler-YAWriter>=0:${PORTSDIR}/textproc/p5-XML-Handler-YAWriter
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
