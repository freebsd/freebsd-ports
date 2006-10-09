# New ports collection makefile for:	p5-HTML-ResolveLink
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-ResolveLink
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Resolve relative links in (X)HTML into absolute URI

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::ResolveLink.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# inherited from www/p5-HTML-Parser
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
