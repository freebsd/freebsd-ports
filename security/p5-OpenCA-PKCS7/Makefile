# New ports collection makefile for:	OpenCA-PKCS7
# Date created:	   02 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	OpenCA-PKCS7
PORTVERSION=	0.9.13
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for basic handling PKCS#7 Signatures

BUILD_DEPENDS=	p5-OpenCA-OpenSSL>=0:${PORTSDIR}/security/p5-OpenCA-OpenSSL \
		p5-OpenCA-X509>=0:${PORTSDIR}/security/p5-OpenCA-X509 \
		p5-X500-DN>=0:${PORTSDIR}/net/p5-X500-DN
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
