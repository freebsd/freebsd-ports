# New ports collection makefile for:    p5-Crypt-DES_EDE3
# Date created:				2002/03/14
# Whom:					jesper
#
# $FreeBSD$
#

PORTNAME=	Crypt-DES_EDE3
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesper@FreeBSD.org
COMMENT=	Perl5 interface to a implementing 3-DES EDE encryption and decryption

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::DES_EDE3.3

.include <bsd.port.mk>
