# Created by: Guy Antony Halse <guy@rucus.ru.za.za>
# $FreeBSD$

PORTNAME=	Mail-Ezmlm
PORTVERSION=	0.08.2
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Ezmlm-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Perl module to allow object methods for ezmlm-idx mailing lists

BUILD_DEPENDS=	${EZMLM_DIR}/bin/ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx \
		p5-Crypt-GPG>=0:${PORTSDIR}/security/p5-Crypt-GPG
RUN_DEPENDS:=	${BUILD_DEPENDS}

EZMLM_DIR?=	${LOCALBASE}

USES=		perl5
USE_PERL5=	configure

.if defined(PACKAGE_BUILDING)
CONFIGURE_ENV=	BSD_BATCH_INSTALL=yes
.endif

.include <bsd.port.mk>
