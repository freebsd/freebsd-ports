# New ports collection makefile for:	p5-Net-SMTP_auth
# Date created:		2006-10-31
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-SMTP_auth
PORTVERSION=	0.08
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Simple Mail Transfer Protocol Client with AUTHentication

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL \
		${SITE_PERL}/Digest/HMAC_MD5.pm:${PORTSDIR}/security/p5-Digest-HMAC

PERL_CONFIGURE=	yes

MAN3=		Net::SMTP_auth.3

.include <bsd.port.mk>
