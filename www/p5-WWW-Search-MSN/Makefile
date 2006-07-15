# New ports collection makefile for:	p5-WWW-Search-MSN
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search-MSN
PORTVERSION=	0.0102
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Backend for searching search.msn.com

BUILD_DEPENDS=	${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/WWW/Search.pm:${PORTSDIR}/www/p5-WWW-Search
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Search::MSN.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from www/p5-WWW-Search
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500701
BUILD_DEPENDS+=	${SITE_PERL}/Encode.pm:${PORTSDIR}/converters/p5-Encode
.endif

.if ${PERL_LEVEL} < 500702
BUILD_DEPENDS+=	${SITE_PERL}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
