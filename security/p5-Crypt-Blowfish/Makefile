# New ports collection makefile for:    p5-Crypt-Blowfish
# Date created:				2000/09/18
# Whom:					patrick@mindstep.com
#
# $FreeBSD$
#

PORTNAME=	Crypt-Blowfish
PORTVERSION=	2.10
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the Blowfish encryption alogorithm

BUILD_DEPENDS=	${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC

PERL_CONFIGURE=	yes

MAN3=		Crypt::Blowfish.3

.include <bsd.port.mk>
