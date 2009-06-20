# New ports collection makefile for:	p5-Pod-Abstract
# Date created:				June 2nd 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Pod-Abstract
PORTVERSION=	0.16
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Abstract document tree for Perl POD documents

BUILD_DEPENDS=	${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

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
