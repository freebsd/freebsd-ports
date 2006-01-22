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
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Creates and updates OPML (Outline Processor Markup Language) files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/SimpleObject.pm:${PORTSDIR}/textproc/p5-XML-SimpleObject
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::OPML.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires Perl5.8
.endif

.include <bsd.port.post.mk>
