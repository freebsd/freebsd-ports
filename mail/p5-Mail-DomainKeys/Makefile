# New ports collection makefile for:	Mail-DomainKeys
# Date created:	   23 May 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Mail-DomainKeys
PORTVERSION=	1.0
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl implementation of DomainKeys

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/RSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		${SITE_PERL}/Email/Address.pm:${PORTSDIR}/mail/p5-Email-Address
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::DomainKeys.3

post-patch:
	@${PERL} -pi -e '$$_="" if $$.>=6 && $$.<=38' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
