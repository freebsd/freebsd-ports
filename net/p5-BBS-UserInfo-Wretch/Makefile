# New ports collection makefile for:	p5-BBS-UserInfo-Wretch
# Date created:		2006-08-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	BBS-UserInfo-Wretch
PORTVERSION=	0.02
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GS/GSLIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Get user information of Wretch-style BBS

RUN_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect

PERL_CONFIGURE=	yes

MAN3=		BBS::UserInfo::Wretch.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800	# Inherited from lang/p5-Expect
IGNORE=		requires Perl 5.8.0 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
