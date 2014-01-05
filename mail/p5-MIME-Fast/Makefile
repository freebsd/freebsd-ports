# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	MIME-Fast
PORTVERSION=	1.6
PORTREVISION=	5
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create, edit, and parse MIME messages (via gmime2 C library)

BUILD_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
LIB_DEPENDS=	libgmime-2.0.so:${PORTSDIR}/mail/gmime2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	PREFIX="${PREFIX}" CCFLAGS="${CCFLAGS} ${PTHREAD_CFLAGS}"

.include <bsd.port.mk>
