# New ports collection makefile for:	p5-Net-HTTPS-NB
# Date created:		2012-03-13
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-HTTPS-NB
PORTVERSION=	0.12
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Non-blocking HTTPS client

BUILD_DEPENDS=	p5-IO-Socket-SSL>=0.98:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Net-HTTP>=0:${PORTSDIR}/net/p5-Net-HTTP
RUN_DEPENDS=	p5-IO-Socket-SSL>=0.98:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Net-HTTP>=0:${PORTSDIR}/net/p5-Net-HTTP

PERL_CONFIGURE=	yes

MAN3=		Net::HTTPS::NB.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
