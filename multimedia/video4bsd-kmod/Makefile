# Ports collection makefile for: video4bsd-kmod
# Date created: 13 January 2010
# Whom:         Andrew Thompson <thompsa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	video4bsd-kmod
PORTVERSION=	0.1.2
CATEGORIES=	multimedia kld
MASTER_SITES=	http://www.selasky.org/hans_petter/video4bsd/releases/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Video4BSD loopback driver for webcamd

USE_BZIP2=	yes
KMODDIR=	/boot/modules
KMODNAME=	video4bsd
PLIST_SUB=	KMODNAME="${KMODNAME}" \
		KMODDIR="${KMODDIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/video4bsd.h ${PREFIX}/include
	${INSTALL_KLD} ${WRKSRC}/${KMODNAME}.ko ${KMODDIR}

.include <bsd.port.post.mk>
