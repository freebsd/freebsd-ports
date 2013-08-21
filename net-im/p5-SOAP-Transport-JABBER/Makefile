# New ports collection makefile for:	p5-SOAP-Transport-JABBER
# Date created:		2011-08-20
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SOAP-Transport-JABBER
PORTVERSION=	0.713
CATEGORIES=	net-im net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A Jabber-based transport backend for SOAP::Lite

BUILD_DEPENDS=	p5-Net-Jabber>=0:${PORTSDIR}/net-im/p5-Net-Jabber \
		p5-SOAP-Lite>=0.711:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	p5-Net-Jabber>=0:${PORTSDIR}/net-im/p5-Net-Jabber \
		p5-SOAP-Lite>=0.711:${PORTSDIR}/net/p5-SOAP-Lite

USE_PERL5=	configure
USES=		perl5

MAN3=		SOAP::Transport::JABBER.3

.include <bsd.port.mk>
