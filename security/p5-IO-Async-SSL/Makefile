# New ports collection makefile for:	p5-IO-Async-SSL
# Date created:		2011-03-07
# Whom:			<ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	IO-Async-SSL
PORTVERSION=	0.06
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/P/PE/PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Use SSL/TLS with IO::Async

RUN_DEPENDS=	p5-IO-Async>=0.29:${PORTSDIR}/devel/p5-IO-Async\
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL

PERL_CONFIGURE=	yes

MAN3=	IO::Async::SSLStream.3 IO::Async::SSL.3

.include <bsd.port.mk>
