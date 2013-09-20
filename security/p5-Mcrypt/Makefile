# Created by: Tatsuki Makino <tatsuki_makino@hotmail.com>
# $FreeBSD$

PORTNAME=	Mcrypt
PORTVERSION=	2.5.7.0
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JESUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Perl extension for the Mcrypt cryptography library

LIB_DEPENDS=	libmcrypt.so:${PORTSDIR}/security/libmcrypt

CONFIGURE_ENV=	MCRYPT_CPPFLAGS=${CPPFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
USE_PERL5=	configure
USES=		perl5

MAN3=		Mcrypt.3

NO_STAGE=	yes
.include <bsd.port.mk>
