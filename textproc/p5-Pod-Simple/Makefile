# New ports collection makefile for:	p5-Pod-Simple # Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Pod-Simple
PORTVERSION=	3.02
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Framework for parsing Pod

BUILD_DEPENDS=	${SITE_PERL}/Text/Wrap.pm:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap \
		${SITE_PERL}/Pod/Escapes.pm:${PORTSDIR}/textproc/p5-Pod-Escapes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Pod::Simple.3 \
		Pod::Simple::Checker.3 \
		Pod::Simple::Debug.3 \
		Pod::Simple::DumpAsText.3 \
		Pod::Simple::DumpAsXML.3 \
		Pod::Simple::HTML.3 \
		Pod::Simple::HTMLBatch.3 \
		Pod::Simple::LinkSection.3 \
		Pod::Simple::Methody.3 \
		Pod::Simple::PullParser.3 \
		Pod::Simple::PullParserEndToken.3 \
		Pod::Simple::PullParserStartToken.3 \
		Pod::Simple::PullParserTextToken.3 \
		Pod::Simple::PullParserToken.3 \
		Pod::Simple::RTF.3 \
		Pod::Simple::Search.3 \
		Pod::Simple::SimpleTree.3 \
		Pod::Simple::Subclassing.3 \
		Pod::Simple::Text.3 \
		Pod::Simple::TextContent.3 \
		Pod::Simple::XMLOutStream.3 \
		perlpod.3 \
		perlpodspec.3

.include <bsd.port.mk>
