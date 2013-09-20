# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	Net-Daemon-SSL
PORTVERSION=	1.0
CATEGORIES=	security net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	simond@irrelevant.org
COMMENT=	Perl5 extension for portable daemons

USES=		perl5
USE_PERL5=	configure

BUILD_DEPENDS+=	p5-Net-Daemon>=0:${PORTSDIR}/net/p5-Net-Daemon \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS+=	p5-Net-Daemon>=0:${PORTSDIR}/net/p5-Net-Daemon \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL

MAN3=		Net::Daemon::SSL.3

NO_STAGE=	yes
.include <bsd.port.mk>
