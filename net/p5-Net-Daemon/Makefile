# New ports collection makefile for:	p5-Net-Daemon
# Date created:				27 Feb 2000
# Whom:	      				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	Net-Daemon
PORTVERSION=	0.29
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.ORG

USE_PERL5=	yes

MAN3=		Net::Daemon.3 \
		Net::Daemon::Log.3 \
		Net::Daemon::Test.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
