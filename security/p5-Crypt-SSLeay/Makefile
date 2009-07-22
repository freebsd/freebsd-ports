# New ports collection makefile for:	p5-Crypt-SSLeay
# Date created:				December-15-2000
# Whom:	      				Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-SSLeay
PORTVERSION=	0.57
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to allow p5-libwww LWP to make https connections

BUILD_DEPENDS=		${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--lib=${OPENSSLBASE}
USE_OPENSSL=	yes

MAN3=		Crypt::SSLeay.3 Net::SSL.3

.include <bsd.port.mk>
