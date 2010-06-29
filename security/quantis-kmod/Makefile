# New ports collection makefile for:    quantis-kmod
# Date created:                 10 May 2010
# Whom:                         Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quantis
DISTVERSION=	v10.06.29
CATEGORIES=	security kld
MASTER_SITES=	http://www.idquantique.com/files/products/quantis/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale
DISTNAME=	${PORTNAME}-${DISTVERSION}-src
PKGNAMESUFFIX=	-kmod

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Kernel driver for Quantis PCI/PCIe random number generator

LICENSE_COMB=	dual
LICENSE=	BSD GPLv2
LICENSE_FILE=	${WRKDIR}/Quantis-${DISTVERSION}/License.txt

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aqo

WRKSRC=		${WRKDIR}/Quantis-${DISTVERSION}/Drivers/Unix/QuantisPci

KMODDIR?=	/boot/modules

SRC_BASE?=	/usr/src

MAKE_ENV+=	KMODDIR=${KMODDIR}

PLIST_FILES=	"@cwd ${KMODDIR}" \
		"quantis.ko" \
		"@unexec kldxref ${KMODDIR}" \
		"@cwd ${PREFIX}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=		requires FreeBSD >= 7
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
