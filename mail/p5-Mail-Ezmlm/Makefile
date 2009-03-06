# New ports collection makefile for:	Mail::Ezmlm
# Date Created: 			18 May 2000
# Whom: 				Guy Antony Halse <guy@rucus.ru.za.za>
#
# $FreeBSD$
#

PORTNAME=	Mail-Ezmlm
PORTVERSION=	0.08.2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Ezmlm-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Perl module to allow object methods for ezmlm-idx mailing lists

BUILD_DEPENDS=	${EZMLM_DIR}/bin/ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx

EZMLM_DIR?=	${LOCALBASE}

PERL_CONFIGURE=	yes

.if defined(PACKAGE_BUILDING)
CONFIGURE_ENV=	BSD_BATCH_INSTALL=yes
.endif

MAN3=		Mail::Ezmlm.3 Mail::Ezmlm::GpgKeyRing.3 Mail::Ezmlm::GpgEzmlm.3

.include <bsd.port.mk>
