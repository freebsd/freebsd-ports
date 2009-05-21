# New ports collection makefile for:	Crypt-Eksblowfish
# Date created:				01 Jun 2008
# Whom:					brix@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Crypt-Eksblowfish
PORTVERSION=	0.007
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl module for the Eksblowfish block cipher

RUN_DEPENDS=	${SITE_PERL}/Class/Mix.pm:${PORTSDIR}/devel/p5-Class-Mix \
		${SITE_PERL}/parent.pm:${PORTSDIR}/devel/p5-parent

PERL_MODBUILD=	yes

MAN3=	Crypt::Eksblowfish.3 \
	Crypt::Eksblowfish::Bcrypt.3 \
	Crypt::Eksblowfish::Blowfish.3 \
	Crypt::Eksblowfish::Family.3 \
	Crypt::Eksblowfish::Subkeyed.3 \
	Crypt::Eksblowfish::Uklblowfish.3

.include <bsd.port.mk>
