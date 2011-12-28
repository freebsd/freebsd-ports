# New ports collection makefile for:	acpi_call
# Date created:				15 Oct 2011
# Whom:					Maxim Ignatenko
#
# $FreeBSD$
#

PORTNAME=	acpi_call
PORTVERSION=	1.0.1
CATEGORIES=	sysutils kld
MASTER_SITES=	http://projects.ukrweb.net/files/ \
		http://imax.in.ua/files/

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	Kernel module for calling ACPI methods from userspace

LICENSE=	BSD

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR} \
		PORTNAME=${PORTNAME}

.if !exists(${SRC_BASE}/sys/sys/module.h)
IGNORE=		requires kernel source files
.endif

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	not relevant for non-x86-derived architectures

post-build:
	@cd ${WRKSRC} && ${MAKE} util

do-install:
	@${INSTALL_KLD} ${WRKSRC}/${PORTNAME}.ko ${KMODDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
