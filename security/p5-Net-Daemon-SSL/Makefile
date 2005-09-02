# New ports collection makefile for:	p5-Net-Daemon-SSL
# Date created:				25 April 2005
# Whom:	      				Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Daemon-SSL
PORTVERSION=	1.0
CATEGORIES=	security net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	simond@irrelevant.org
COMMENT=	Perl5 extension for portable daemons

PERL_CONFIGURE=	yes

BUILD_DEPENDS+=	${SITE_PERL}/Net/Daemon.pm:${PORTSDIR}/net/p5-Net-Daemon \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS+=	${SITE_PERL}/Net/Daemon.pm:${PORTSDIR}/net/p5-Net-Daemon \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL

MAN3=		Net::Daemon::SSL.3

.include <bsd.port.mk>
