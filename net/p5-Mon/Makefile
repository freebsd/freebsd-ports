# New ports collection makefile for:	p5-Mon
# Date created:			October 30th, 2000
# Whom:	      			Nicholas Esborn <nick@netdot.net>
#
# $FreeBSD$
#

PORTNAME=	Mon
PORTVERSION=	0.9
CATEGORIES=	net sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mon
PKGNAMEPREFIX=	p5-
DISTNAME=	Mon-${PORTVERSION}

MAINTAINER=	nick@netdot.net

USE_PERL5=	YES

MAN3=		Mon::SNMP.3 \
		Mon::Client.3 \
		Mon::Protocol.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
