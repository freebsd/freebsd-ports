# New ports collection makefile for:	p5-Crypt-RSA
# Date created:				Tue Sep 11 10:31:23 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-RSA
PORTVERSION=	1.99
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	RSA public-key cryptosystem

RUN_DEPENDS=	p5-Class-Loader>=2.00:${PORTSDIR}/devel/p5-Class-Loader \
		p5-Convert-ASCII-Armour>=0:${PORTSDIR}/converters/p5-Convert-ASCII-Armour \
		p5-Crypt-CBC>=0:${PORTSDIR}/security/p5-Crypt-CBC \
		p5-Crypt-Primes>=0.38:${PORTSDIR}/security/p5-Crypt-Primes \
		p5-Crypt-Random>=0.34:${PORTSDIR}/security/p5-Crypt-Random \
		p5-Data-Buffer>=0:${PORTSDIR}/misc/p5-Data-Buffer \
		p5-Digest-MD2>=0:${PORTSDIR}/security/p5-Digest-MD2 \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Math-Pari>=2.001804:${PORTSDIR}/math/p5-Math-Pari \
		p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions \
		p5-Tie-EncryptedHash>=0:${PORTSDIR}/security/p5-Tie-EncryptedHash

PERL_CONFIGURE=	yes

MAN3=	Crypt::RSA.3 \
	Crypt::RSA::DataFormat.3 \
	Crypt::RSA::Debug.3 \
	Crypt::RSA::ES::OAEP.3 \
	Crypt::RSA::ES::PKCS1v15.3 \
	Crypt::RSA::Errorhandler.3 \
	Crypt::RSA::Key.3 \
	Crypt::RSA::Key::Private.3 \
	Crypt::RSA::Key::Private::SSH.3 \
	Crypt::RSA::Key::Public.3 \
	Crypt::RSA::Key::Public::SSH.3 \
	Crypt::RSA::Primitives.3 \
	Crypt::RSA::SS::PKCS1v15.3 \
	Crypt::RSA::SS::PSS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
