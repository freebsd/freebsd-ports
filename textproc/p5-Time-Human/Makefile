# New ports collection makefile for:	p5-Time-Human
# Date created:				July 24th, 2004
# Whom:	      				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Time-Human
PORTVERSION=	1.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time
PKGNAMEPREFIX=	p5-

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Convert localtime() format to "speaking clock" time

PERL_CONFIGURE=	yes

MAN3=		Time::Human.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BROKEN=		Does not build with Perl 5.005.
.endif

.include <bsd.port.post.mk>
