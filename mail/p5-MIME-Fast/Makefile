# New ports collection makefile for:	MIME-Fast
# Date created:	   08 December 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MIME-Fast
PORTVERSION=	1.6
PORTREVISION=	5
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create, edit, and parse MIME messages (via gmime2 C library)

BUILD_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
LIB_DEPENDS=	gmime-2.0.4:${PORTSDIR}/mail/gmime2
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX="${PREFIX}" CCFLAGS="${CCFLAGS} ${PTHREAD_CFLAGS}"

MAN3=		MIME::Fast.3

.include <bsd.port.mk>
