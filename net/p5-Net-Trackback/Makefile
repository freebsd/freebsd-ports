# Created by: Cory R. King <coryking@mozimedia.com>
# $FreeBSD$

PORTNAME=	Net-Trackback
PORTVERSION=	1.01
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	An interface for developing Trackback clients and servers

BUILD_DEPENDS=	p5-Class-ErrorHandler>=0.01:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-Class-ErrorHandler>=0.01:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
