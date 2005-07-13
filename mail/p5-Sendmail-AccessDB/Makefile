# New ports collection makefile for:	p5-Sendmail-AccessDB
# Date created:				29 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	Sendmail-AccessDB
PORTVERSION=	0.09
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Sendmail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Perl5 interface to the Sendmail access.db list

BUILD_DEPENDS=	${SITE_PERL}/mach/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Sendmail::AccessDB.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500806
IGNORE=		needs Perl 5.8.6 or above (lang/perl5.8)
.endif

.include <bsd.port.post.mk>
