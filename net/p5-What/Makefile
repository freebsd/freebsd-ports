# New ports collection makefile for:	p5-What
# Date created:		2006-07-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	What
PORTVERSION=	1.01
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/T/TP/TPG
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Find out about running services

BUILD_DEPENDS=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		What.3 What::MTA.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from devel/p5-Error
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 then try again
.endif

.if ${PERL_LEVEL} < 500702
BUILD_DEPENDS+=	${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net
.endif

.include <bsd.port.post.mk>
