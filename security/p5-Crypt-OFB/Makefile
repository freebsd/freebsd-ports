# New ports collection makefile for:	p5-Crypt-OFB
# Date created:				Nov 2 2003
# Whom:	      				clsung
#
# $FreeBSD$
#

PORTNAME=	Crypt-OFB
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Encrypt Data using OFB Mode

BUILD_DEPENDS=	${SITE_PERL}/Crypt/ECB.pm:${PORTSDIR}/security/p5-Crypt-ECB
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::OFB.3

.include <bsd.port.mk>
