# New ports collection makefile for:	p5-XML-DOM-Lite
# Date created:		2006-08-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-DOM-Lite
PORTVERSION=	0.15
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lite Pure Perl XML DOM Parser Kit

PERL_CONFIGURE=	yes

MAN3=		XML::DOM::Lite.3 XML::DOM::Lite::Document.3 \
		XML::DOM::Lite::NodeList.3 XML::DOM::Lite::Parser.3 \
		XML::DOM::Lite::XPath.3 XML::DOM::Lite::XSLT.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500803
IGNORE=		requires Perl 5.8.3 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
