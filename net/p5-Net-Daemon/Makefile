# New ports collection makefile for:	p5-Net-Daemon
# Version required:			0.29
# Date created:				27 Feb 2000
# Whom:	      				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	Net-Daemon-0.29
PKGNAME=	p5-Net-Daemon-0.29
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=	vanilla@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		Net::Daemon.3 \
		Net::Daemon::Log.3 \
		Net::Daemon::Test.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
