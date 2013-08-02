# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Pod-Abstract
PORTVERSION=	0.20
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstract document tree for Perl POD documents

BUILD_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		paf.1
MAN3=		Pod::Abstract.3 \
		Pod::Abstract::BuildNode.3 \
		Pod::Abstract::Filter.3 \
		Pod::Abstract::Filter::add_podcmds.3 \
		Pod::Abstract::Filter::clear_podcmds.3 \
		Pod::Abstract::Filter::cut.3 \
		Pod::Abstract::Filter::find.3 \
		Pod::Abstract::Filter::number_sections.3 \
		Pod::Abstract::Filter::overlay.3 \
		Pod::Abstract::Filter::sort.3 \
		Pod::Abstract::Filter::summary.3 \
		Pod::Abstract::Filter::uncut.3 \
		Pod::Abstract::Filter::unoverlay.3 \
		Pod::Abstract::Node.3 \
		Pod::Abstract::Parser.3 \
		Pod::Abstract::Path.3 \
		Pod::Abstract::Serial.3 \
		Pod::Abstract::Tree.3

.include <bsd.port.mk>
