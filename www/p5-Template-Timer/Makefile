# New ports collection makefile for:	www/p5-Template-Timer
# Date created:				04 May 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Timer
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Rudimentary profiling for Template Toolkit

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Template::Timer.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE=	requires Perl 5.6. Install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
