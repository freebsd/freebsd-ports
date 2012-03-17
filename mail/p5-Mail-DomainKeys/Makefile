# New ports collection makefile for:	Mail-DomainKeys
# Date created:	   23 May 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Mail-DomainKeys
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl implementation of DomainKeys

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Crypt-OpenSSL-RSA>=0:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::DomainKeys.3

post-patch:
	@${PERL} -pi -e '$$_="" if $$.>=6 && $$.<=38' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
