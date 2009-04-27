# New ports collection makefile for:	sysutils/p5-Schedule-Cron
# Date created:				03 January 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Schedule-Cron
PORTVERSION=	0.98
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Schedule::Cron - cron-like scheduler for Perl subroutines

BUILD_DEPENDS=	${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Schedule::Cron.3

.include <bsd.port.mk>
