# New ports collection makefile for:	p5-Net-OpenID-Consumer
# Date created:		2007-05-04
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenID-Consumer
PORTVERSION=	1.12
CATEGORIES=	net security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Library for consumers of OpenID identities

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Net-OpenID-Common>=0:${PORTSDIR}/security/p5-Net-OpenID-Common \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::OpenID::Association.3 Net::OpenID::ClaimedIdentity.3 \
		Net::OpenID::Consumer.3 Net::OpenID::VerifiedIdentity.3

.if defined(MAINTAINER_MODE)
regression-test: build
	cd ${WRKSRC} && ${MAKE} test
.endif

.include <bsd.port.mk>
