# Created by: Guy Antony Halse <guy@rucus.ru.za.za>
# $FreeBSD$

PORTNAME=	Mail-Ezmlm
PORTVERSION=	0.08.2
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Ezmlm-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to allow object methods for ezmlm-idx mailing lists

LICENSE=	BSD3CLAUSE GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${EZMLM_DIR}/bin/ezmlm-idx:mail/ezmlm-idx \
		p5-Crypt-GPG>=0:security/p5-Crypt-GPG
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

EZMLM_DIR?=	${LOCALBASE}

.if defined(PACKAGE_BUILDING)
CONFIGURE_ENV=	BSD_BATCH_INSTALL=yes
.endif

.include <bsd.port.mk>
