# Created by: Gleb Kurtsou <gleb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pefs
DISTVERSION=	2018-11-26
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/gleb
PKGNAMESUFFIX=	-kmod

MAINTAINER=	gleb@FreeBSD.org
COMMENT=	PEFS kernel level stacked cryptographic filesystem

LICENSE=	BSD2CLAUSE

BROKEN_armv6=		fails to compile: implicit declaration of function 'cp15_pmccntr_get' is invalid in C99
BROKEN_DragonFly=	fails to build: don't know how to make vnode_if.h
ONLY_FOR_ARCHS=		amd64 armv6 i386
ONLY_FOR_ARCHS_REASON=	untested on any other arch

USES=		kmod uidfix

MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man" \
		NO_MANCOMPRESS=

OPTIONS_DEFINE=	AESNI
OPTIONS_DEFAULT=
AESNI_DESC=	Enable AES-NI hardware acceleration

PLIST_FILES=	sbin/pefs \
		lib/pam_pefs.so \
		man/man8/pam_pefs.8.gz \
		man/man8/pefs.8.gz \
		${KMODDIR}/pefs.ko

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAESNI}
MAKE_ENV+=	PEFS_AESNI=yes
.endif

.if ${OPSYS} == FreeBSD
PLIST_FILES+=	lib/pam_pefs.so.6
.endif

.include <bsd.port.mk>
