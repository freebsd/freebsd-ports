# New ports collection Makefile for:	p5-Crypt-X509
# Date created:				18 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-X509
PORTVERSION=	0.40
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension to parse X.509 certificates

BUILD_DEPENDS=	${SITE_PERL}/Convert/ASN1.pm:${PORTSDIR}/converters/p5-Convert-ASN1

PERL_CONFIGURE=	yes

MAN3=		Crypt::X509.3

.include <bsd.port.mk>
