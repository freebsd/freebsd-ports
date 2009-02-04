# New ports collection makefile for:	p5-Mcrypt
# Date created:	27 Jan 2009
# Whom:		Tatsuki
#
# $FreeBSD$
#

PORTNAME=	Mcrypt
PORTVERSION=	2.5.7.0
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/J/JE/JESUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Perl extension for the Mcrypt cryptography library

LIB_DEPENDS=	mcrypt.[8]:${PORTSDIR}/security/libmcrypt

MAN3=		Mcrypt.3
PERL_CONFIGURE=	yes
CONFIGURE_ENV=	MCRYPT_CPPFLAGS=${CPPFLAGS}

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
