# New ports collection makefile for:	sysutils/p5-Schedule-Cron
# Date created:				03 January 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Schedule-Cron
PORTVERSION=	0.05
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Schedule
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Schedule::Cron.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
