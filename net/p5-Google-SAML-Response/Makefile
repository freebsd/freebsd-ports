# New ports collection makefile for:	p5-Google-SAML-Response
# Date created:		2009-08-05
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Google-SAML-Response
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	SAML responses for Google\'s SSO implementation

RUN_DEPENDS=	p5-Crypt-OpenSSL-Bignum>0:${PORTSDIR}/security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-DSA>0:${PORTSDIR}/security/p5-Crypt-OpenSSL-DSA \
		p5-Crypt-OpenSSL-RSA>0:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		p5-Digest-SHA>0:${PORTSDIR}/security/p5-Digest-SHA \
		p5-File-Which>0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-Google-SAML-Request>0:${PORTSDIR}/net/p5-Google-SAML-Request \
		p5-TimeDate>0:${PORTSDIR}/devel/p5-TimeDate \
		p5-XML-Canonical>0:${PORTSDIR}/textproc/p5-XML-Canonical \
		p5-XML-CanonicalizeXML>0:${PORTSDIR}/textproc/p5-XML-CanonicalizeXML

PERL_CONFIGURE=	yes

MAN3=		Google::SAML::Response.3

.include <bsd.port.mk>
