# New ports collection makefile for:	p5-LWPx-TimedHTTP
# Date created:		2011-11-11
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	LWPx-TimedHTTP
PORTVERSION=	1.8
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Time the different stages of an HTTP request

BUILD_DEPENDS=	p5-HTTP-Daemon>=0:${PORTSDIR}/www/p5-HTTP-Daemon \
		p5-libwww>=6:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-libwww>=6:${PORTSDIR}/www/p5-libwww

USE_PERL5=	configure
USES=		perl5

MAN3=		LWPx::TimedHTTP.3

.include <bsd.port.mk>
