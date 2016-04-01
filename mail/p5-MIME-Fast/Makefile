# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	MIME-Fast
PORTVERSION=	1.6
PORTREVISION=	8
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create, edit, and parse MIME messages (via gmime2 C library)

LIB_DEPENDS=	libgmime-2.0.so:mail/gmime2

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	PREFIX="${PREFIX}" CCFLAGS="${CCFLAGS}"

.include <bsd.port.mk>
