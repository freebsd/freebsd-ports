# ex:ts=8
# Ports collection makefile for:	XML-OPML
# Date created:			Nov 21, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	XML-OPML
PORTVERSION=	0.26
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Creates and updates OPML (Outline Processor Markup Language) files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/SimpleObject.pm:${PORTSDIR}/textproc/p5-XML-SimpleObject
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	XML::OPML.3

.include <bsd.port.mk>
