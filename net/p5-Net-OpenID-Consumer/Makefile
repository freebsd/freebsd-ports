# New ports collection makefile for:	p5-Net-OpenID-Consumer
# Date created:		2007-05-04
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenID-Consumer
PORTVERSION=	0.14
CATEGORIES=	net security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library for consumers of OpenID identities

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Crypt/DH.pm:${PORTSDIR}/security/p5-Crypt-DH \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/URI/Fetch.pm:${PORTSDIR}/www/p5-URI-Fetch
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::OpenID::Association.3 Net::OpenID::ClaimedIdentity.3 \
		Net::OpenID::Consumer.3 Net::OpenID::VerifiedIdentity.3

.include <bsd.port.mk>
