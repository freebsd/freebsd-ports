# New ports collection makefile for:    p5-XML-RSS-JavaScript
# Date created:				31 Oct 2003
# Whom:					Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS-JavaScript
PORTVERSION=	0.60
CATEGORIES=	textproc www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to serialize your RSS as JavaScript

BUILD_DEPENDS=	${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS

PERL_CONFIGURE=	yes

MAN3=		XML::RSS::JavaScript.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
