# New ports collection makefile for:	p5-Net-OpenID-Consumer
# Date created:		2007-05-04
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenID-Consumer
PORTVERSION=	1.13
CATEGORIES=	net security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Library for consumers of OpenID identities

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Net-OpenID-Common>=1.13:${PORTSDIR}/security/p5-Net-OpenID-Common \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::OpenID::Association.3 Net::OpenID::ClaimedIdentity.3 \
		Net::OpenID::Consumer.3 Net::OpenID::VerifiedIdentity.3

.if defined(MAINTAINER_MODE)
regression-test: build
	cd ${WRKSRC} && ${MAKE} test
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA
RUN_DEPENDS+=	p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA
.endif

.include <bsd.port.post.mk>
