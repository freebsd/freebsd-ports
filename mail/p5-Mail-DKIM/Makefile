# ports collection makefile for:	p5-Mail-DKIM
# Date created:				16 July 2006
# Whom:					Yoshisato YANAGISAWA
#
# $FreeBSD$
#

PORTNAME=	Mail-DKIM
PORTVERSION=	0.37
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	yanagisawa@csg.is.titech.ac.jp
COMMENT=	Perl5 module to process and/or create DKIM email

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/RSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA.pm:${PORTSDIR}/security/p5-Digest-SHA \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools
BUILD_DEPENDS=	${RUN_DEPENDS}

MASTER_SITE_BACKUP+=	http://jason.long.name/dkimproxy/

PERL_CONFIGURE=	yes

MAN3=		Mail::DKIM.3 \
		Mail::DKIM::Algorithm::Base.3 \
		Mail::DKIM::AuthorDomainPolicy.3 \
		Mail::DKIM::Canonicalization::Base.3 \
		Mail::DKIM::Canonicalization::DkimCommon.3 \
		Mail::DKIM::DkimPolicy.3 \
		Mail::DKIM::DkPolicy.3 \
    		Mail::DKIM::DkSignature.3 \
		Mail::DKIM::Policy.3 \
		Mail::DKIM::PrivateKey.3 \
		Mail::DKIM::PublicKey.3 \
		Mail::DKIM::Signature.3 \
		Mail::DKIM::Signer.3 \
		Mail::DKIM::SignerPolicy.3 \
		Mail::DKIM::Verifier.3 \
		Mail::DKIM::TextWrap.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/dkim*.pl ${PREFIX}/bin

.include <bsd.port.mk>
