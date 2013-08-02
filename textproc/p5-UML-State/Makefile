# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	UML-State
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that produce simple UML state diagrams

BUILD_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		drawstatexml.pl.1 drawstate.pl.1
MAN3=		UML::drawstate.3 \
		UML::drawstatexml.3 \
		UML::State.3

.include <bsd.port.mk>
