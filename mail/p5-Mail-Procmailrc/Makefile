# ex:ts=8
# Ports collection makefile for:	p5-Mail-Procmailrc
# Date created:			Sep 13, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Mail-Procmailrc
PORTVERSION=	1.03
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://scott.wiersdorf.org/perl/
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PERL_CONFIGURE=	YES

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BROKEN=		This port requires perl 5.6.0
.endif

.include <bsd.port.post.mk>
