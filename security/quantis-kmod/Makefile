# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quantis
DISTVERSION=	v13.04.29
CATEGORIES=	security kld
MASTER_SITES=	http://www.idquantique.com/~download/Quantis/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale
PKGNAMESUFFIX=	-kmod
DISTNAME=	Quantis-${DISTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Kernel driver for Quantis PCI/PCIe random number generator

LICENSE=	BSD GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKDIR}/Quantis-${DISTVERSION}/License.txt

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aqo

WRKSRC=		${WRKDIR}/Quantis-${DISTVERSION}/Drivers/Unix/QuantisPci

KMODDIR?=	/boot/modules

MAKE_ENV+=	KMODDIR=${KMODDIR}

PLIST_FILES=	"@cwd ${KMODDIR}" \
		"quantis.ko" \
		"@unexec kldxref ${KMODDIR}" \
		"@cwd ${PREFIX}"

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
