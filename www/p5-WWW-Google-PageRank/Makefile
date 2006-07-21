# New ports collection makefile for:	p5-WWW-Google-PageRank
# Date created:		2006-07-19
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-Google-PageRank
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	This's a Perl interface for querying google pagerank

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Google::PageRank.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/base.pm:${PORTSDIR}/devel/p5-Class-Fields
.endif

.include <bsd.port.post.mk>
