PORTNAME=	Mail-IMAPClient
PORTVERSION=	3.43
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLOBBES
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to talk to a IMAP4rev1 (RFC2060) server

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Parse-RecDescent>=1.940000:devel/p5-Parse-RecDescent \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	</dev/null
NO_ARCH=	yes

OPTIONS_DEFINE=		CRAMMD5 DIGESTMD5 NTLM
OPTIONS_DEFAULT=	CRAMMD5 DIGESTMD5

CRAMMD5_DESC=		Allow CRAM-MD5 auth scheme
CRAMMD5_RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC

DIGESTMD5_DESC=		Allow DIGEST-MD5 auth scheme
DIGESTMD5_RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
			p5-Digest-MD5>=0:security/p5-Digest-MD5

NTLM_DESC=		Allow NTLM auth scheme
NTLM_RUN_DEPENDS=	p5-Authen-NTLM>=0:security/p5-Authen-NTLM

.include <bsd.port.mk>
