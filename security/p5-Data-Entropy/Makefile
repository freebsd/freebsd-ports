# New ports collection makefile for:	p5-Data-Entropy
# Date created:		2006-07-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Entropy
PORTVERSION=	0.007
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Entropy (randomness) management

RUN_DEPENDS=	p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-Data-Float>=0.008:${PORTSDIR}/math/p5-Data-Float \
		p5-HTTP-Lite>=0.22:${PORTSDIR}/www/p5-HTTP-Lite \
		p5-Params-Classify>=0:${PORTSDIR}/devel/p5-Params-Classify

PERL_MODBUILD=	yes

MAN3=		Data::Entropy.3 \
		Data::Entropy::Algorithms.3 \
		Data::Entropy::RawSource::CryptCounter.3 \
		Data::Entropy::RawSource::Local.3 \
		Data::Entropy::RawSource::RandomOrg.3 \
		Data::Entropy::RawSource::RandomnumbersInfo.3 \
		Data::Entropy::Source.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
