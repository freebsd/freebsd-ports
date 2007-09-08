# New ports collection makefile for:	Digest-SHA2
# Date created:	   06 August 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Digest-SHA2
PORTVERSION=	1.1.1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interface to the SHA-2 algorithms

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Digest/base.pm:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		Has numerious known bugs, deprecated in favor of Digest::SHA
EXPIRATION_DATE=	2007-09-10

PERL_CONFIGURE=	yes

MAN3=		Digest::SHA2.3

.include <bsd.port.mk>
