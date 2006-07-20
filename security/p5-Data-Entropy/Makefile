# New ports collection makefile for:	p5-Data-Entropy
# Date created:		2006-07-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Entropy
PORTVERSION=	0.000
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Entropy (randomness) management

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/Rijndael.pm:${PORTSDIR}/security/p5-Crypt-Rijndael \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt \
		${SITE_PERL}/Math/BigRat.pm:${PORTSDIR}/math/p5-Math-BigRat \
		${SITE_PERL}/Params/Classify.pm:${PORTSDIR}/devel/p5-Params-Classify

PERL_CONFIGURE=	yes

MAN3=		Data::Entropy::RawSource::RandomOrg.3 \
		Data::Entropy::RawSource::CryptCounter.3 \
	       	Data::Entropy::Algorithms.3 \
	       	Data::Entropy::RawSource::RandomnumbersInfo.3 \
	       	Data::Entropy::Source.3 Data::Entropy.3 \
	       	Data::Entropy::RawSource::Local.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from www/p5-libwww
IGNORE=		requires Perl 5.6.0 or newer.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
