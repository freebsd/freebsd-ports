# New ports collection makefile for:   p5-Mail-Alias
# Date created:        07 July 2004
# Whom:                snowchyld
#
# $FreeBSD$
#

PORTNAME=	Mail-Alias
PORTVERSION=	1.12
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	mail-p5-mail-alias-freebsd-ports@snowchyld.org
COMMENT=	Mail::Alias

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500100
IGNORE=	"This port requires perl 5.1 or newer.  Install lang/perl5 or lang/perl5.8 and try again."
.endif

MAN3=	Mail::Alias.3

.include <bsd.port.post.mk>
