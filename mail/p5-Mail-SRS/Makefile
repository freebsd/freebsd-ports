# New ports collection makefile for:   p5-Mail-SRS
# Date created:        24 May 2004
# Whom:                snowchyld
#
# $FreeBSD$
#

PORTNAME=	Mail-SRS
PORTVERSION=	0.30
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	mail-srs-bsd-port@snowchyld.org
COMMENT=	Sender Rewriting Scheme

BUILD_DEPENDS=	${SITE_PERL}/Digest/HMAC_SHA1.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Mail::SRS.3 \
	Mail::SRS::DB.3 \
	Mail::SRS::Daemon.3 \
	Mail::SRS::Guarded.3 \
	Mail::SRS::Reversible.3 \
	Mail::SRS::Shortcut.3
MAN1=	srs.1 \
	srsd.1

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
