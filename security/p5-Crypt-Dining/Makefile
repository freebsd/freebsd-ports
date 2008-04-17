# New ports collection makefile for:	p5-Crypt-Dining
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-Dining
PORTVERSION=	1.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	The Dining Cryptographers' Protocol

BUILD_DEPENDS=	${SITE_PERL}/Crypt/Random.pm:${PORTSDIR}/security/p5-Crypt-Random \
		${SITE_PERL}/Net/Address/IPv4/Local.pm:${PORTSDIR}/net/p5-Net-Address-IPv4-Local
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Crypt::Dining.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
