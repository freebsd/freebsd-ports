# New ports collection makefile for:	Mail::Ezmlm
# Date Created: 			18 May 2000
# Whom: 				Guy Antony Halse <guy@rucus.ru.za.za>
#
# $FreeBSD$
#

PORTNAME=	Mail-Ezmlm
PORTVERSION=	0.05.1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		ftp://ftp.rucus.ru.ac.za/users/guy/ezmlm/
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-
DISTNAME=	Ezmlm-${PORTVERSION}

MAINTAINER=	guy-ezmlm@rucus.ru.ac.za
COMMENT=	Perl module to allow object methods for ezmlm-idx mailing lists

BUILD_DEPENDS=	${EZMLM_DIR}/bin/ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx

IS_INTERACTIVE=	YES

EZMLM_DIR?=	${LOCALBASE}
USE_PERL5=	YES
MAN3=		Mail::Ezmlm.3

# For this version, since it is a bugfix
WRKSRC=		${WRKDIR}/Ezmlm-0.05

do-configure:
.if defined(BATCH)
		@cd ${WRKSRC}; ${SETENV} BSD_BATCH_INSTALL=yes ${PERL5} Makefile.PL
.else
		@cd ${WRKSRC}; ${PERL5} Makefile.PL
.endif

.include <bsd.port.mk>
