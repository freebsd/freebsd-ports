# New ports collection makefile for:	p5-POSIX-Regex
# Date created:		2006-08-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POSIX-Regex
PORTVERSION=	0.90.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OO interface for the gnu regex engine

PERL_CONFIGURE=	yes

MAN3=		POSIX::Regex.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BUILD_DEPENDS+=	${SITE_PERL}/ExtUtils/Constant.pm:${PORTSDIR}/devel/p5-ExtUtils-Constant
.endif

.include <bsd.port.post.mk>
