# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Blog-Spam
PORTVERSION=	1.0.2
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SKX
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Blog & Forum SPAM Detection

RUN_DEPENDS=	p5-Net-CIDR-Lite>=0:${PORTSDIR}/net/p5-Net-CIDR-Lite \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-RPC-XML>=0:${PORTSDIR}/net/p5-RPC-XML \
		p5-URI-Find>=0:${PORTSDIR}/textproc/p5-URI-Find \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
