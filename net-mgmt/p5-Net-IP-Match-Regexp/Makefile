# New ports collection makefile for:   net-mgmt/p5-Net-IP-Match-Regexp
# Date created:                                1 Aug 2006
# Whom:                                        Timur I. Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IP-Match-Regexp
PORTVERSION=	0.94
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	bat@cpan.org
COMMENT=	Efficiently match IP addresses against IP ranges via regexp

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_MODBUILD=	yes

MAN3=	Net::IP::Match::Regexp.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
