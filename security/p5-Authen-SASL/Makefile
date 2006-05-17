# New ports collection makefile for:	p5-Authen-SASL
# Date created:				January 3rd 2003
# Whom:	      				Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-SASL
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for SASL authentication

BUILD_DEPENDS=	\
	p5-Digest-MD5>0:${PORTSDIR}/security/p5-Digest-MD5 \
	p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC

OPTIONS=	KERBEROS "Enable Kerberos support" On

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	AUTOMATED_TESTING=yes

MAN3+=	Authen::SASL.3
MAN3+=	Authen::SASL::Perl.3
MAN3+=	Authen::SASL::Perl::ANONYMOUS.3
MAN3+=	Authen::SASL::Perl::CRAM_MD5.3
MAN3+=	Authen::SASL::Perl::DIGEST_MD5.3
MAN3+=	Authen::SASL::Perl::EXTERNAL.3
MAN3+=	Authen::SASL::Perl::GSSAPI.3
MAN3+=	Authen::SASL::Perl::LOGIN.3
MAN3+=	Authen::SASL::Perl::PLAIN.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.if !defined(WITHOUT_KERBEROS)
BUILD_DEPENDS+=	p5-GSSAPI>0:${PORTSDIR}/security/p5-GSSAPI
.endif
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.post.mk>
