# New ports collection makefile for:	p5-Net-OpenID-Consumer
# Date created:		2007-05-04
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenID-Consumer
PORTVERSION=	1.06
CATEGORIES=	net security perl5
MASTER_SITES=	CPAN/../../authors/id/G/GU/GUGU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library for consumers of OpenID identities

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Crypt-DH-GMP>=0.0.5:${PORTSDIR}/net/p5-Crypt-DH-GMP \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::OpenID::Association.3 Net::OpenID::ClaimedIdentity.3 \
		Net::OpenID::Consumer.3 Net::OpenID::IndirectMessage.3 \
    		Net::OpenID::URIFetch.3 Net::OpenID::VerifiedIdentity.3 \
		Net::OpenID::Yadis.3 Net::OpenID::Yadis::Service.3

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -delete

.include <bsd.port.mk>
