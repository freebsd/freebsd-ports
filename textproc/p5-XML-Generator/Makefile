# New ports collection makefile for:	XML::Generator
# Date created:				22 January 2004
# Whom:					Andreas Heil <ah@linux-hq.de>
#
# $FreeBSD$
#

PORTNAME=	XML-Generator
PORTVERSION=	0.99
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ah@linux-hq.de
COMMENT=	A simple Perl module for generating XML documents

RUN_DEPENDS=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
		${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Generator.3 XML::Generator::DOM.3

test:
	@(cd ${WRKSRC} && make test)

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again.
.endif

.include <bsd.port.post.mk>
