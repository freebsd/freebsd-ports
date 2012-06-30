# New ports collection makefile for:	p5-Net-Daemon-SSL
# Date created:				25 April 2005
# Whom:	      				Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Daemon-SSL
PORTVERSION=	1.0
CATEGORIES=	security net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	simond@irrelevant.org
COMMENT=	Perl5 extension for portable daemons

PERL_CONFIGURE=	yes

BUILD_DEPENDS+=	p5-Net-Daemon>=0:${PORTSDIR}/net/p5-Net-Daemon \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS+=	p5-Net-Daemon>=0:${PORTSDIR}/net/p5-Net-Daemon \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL

MAN3=		Net::Daemon::SSL.3

.include <bsd.port.mk>
