# New ports collection makefile for:	MIME-Fast
# Date created:	   08 December 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MIME-Fast
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MIME
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Create, edit and parse MIME messages (via gmime2 C library)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
LIB_DEPENDS=	gmime-2.0:${PORTSDIR}/mail/gmime2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX="${PREFIX}" CCFLAGS="${CCFLAGS} ${PTHREAD_CFLAGS}"

MAN3=		MIME::Fast.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	Perl 5.8 or newer required. Install lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
