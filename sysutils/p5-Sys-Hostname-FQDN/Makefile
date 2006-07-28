# New ports collection makefile for:	p5-Sys-Hostname-FQDN
# Date created:		2006-07-23
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Sys-Hostname-FQDN
PORTVERSION=	0.07
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Sys
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Get the short or long hostname

PERL_CONFIGURE=	yes

MAN3=		Sys::Hostname::FQDN.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/base.pm:${PORTSDIR}/devel/p5-Class-Fields
RUN_DEPENDS+=	${SITE_PERL}/base.pm:${PORTSDIR}/devel/p5-Class-Fields
.endif

.include <bsd.port.post.mk>
