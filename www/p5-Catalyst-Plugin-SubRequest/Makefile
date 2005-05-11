# ex:ts=8
# Ports collection makefile for:	p5-Catalyst-Plugin-SubRequest
# Date created:			May 6, 2005
# Whom:				Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-SubRequest
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	hcoyote@ghostar.org
COMMENT=	Make subrequests to actions in Catalyst

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::SubRequest.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
