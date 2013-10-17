# Created by: Gleb Kurtsou <gleb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pefs
DISTVERSION=	2013-10-13
CATEGORIES=	sysutils kld
MASTER_SITES=	https://pefs.googlecode.com/files/
PKGNAMESUFFIX=	-kmod

MAINTAINER=	gleb@FreeBSD.org
COMMENT=	PEFS kernel level stacked cryptographic filesystem

LICENSE=	BSD

SSP_UNSAFE=	kernel module does not support ssp
FETCH_ARGS=	-Fpr		# work around 302 redirect

KMODDIR?=	/boot/modules
PLIST_SUB=	KMODDIR=${KMODDIR}
MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man" \
		NO_MANCOMPRESS= \
		KMODDIR="${KMODDIR}" SYSDIR="${SRC_BASE}/sys"

MAN8=		pam_pefs.8 pefs.8

ONLY_FOR_ARCHS=	i386 amd64	# not tested on other archs

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		requires fairly recent FreeBSD-STABLE, or FreeBSD-CURRENT
.endif

.include <bsd.port.post.mk>
