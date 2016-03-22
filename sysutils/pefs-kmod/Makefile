# Created by: Gleb Kurtsou <gleb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pefs
DISTVERSION=	2016-03-17
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/gleb
PKGNAMESUFFIX=	-kmod

MAINTAINER=	gleb@FreeBSD.org
COMMENT=	PEFS kernel level stacked cryptographic filesystem

LICENSE=	BSD2CLAUSE

MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man" \
		NO_MANCOMPRESS=

ONLY_FOR_ARCHS=	i386 amd64 armv6
ONLY_FOR_ARCHS_REASON= Untested on any other arch.

USES=		kmod uidfix

OPTIONS_DEFINE=	AESNI
OPTIONS_DEFAULT=
AESNI_DESC=	Enable AES-NI hardware acceleration

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAESNI}
MAKE_ENV+=	PEFS_AESNI=yes
.endif

.include <bsd.port.mk>
