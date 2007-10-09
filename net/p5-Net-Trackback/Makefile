# New ports collection makefile for:	p5-Net-Trackback
# Date created:				07 October 2007
# Whom:					Cory R. King <coryking@mozimedia.com>
#
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

MAN3=		Net::Trackback.3 \
		Net::Trackback::Client.3 \
		Net::Trackback::Data.3 \
		Net::Trackback::Message.3 \
		Net::Trackback::Ping.3 \
		Net::Trackback::Server.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
