# Ports collection makefile for: ipmi-kmod
# Date created: 18 April 2006
# Whom:         Nick Barkas <snb@threerings.net>
#
# $FreeBSD$
#

PORTNAME=	ipmi-kmod
PORTVERSION=	20060418
CATEGORIES=	sysutils
MASTER_SITES=	http://dpw.threerings.net/projects/ipmi-kmod/

MAINTAINER=	snb@threerings.net
COMMENT=	Backport of ipmi driver from FreeBSD 7-CURRENT for FreeBSD 6.x

PLIST_FILES=	include/sys/ipmi.h
PLIST_DIRS=	include/sys

# We want to install the module in /boot/modules rather than /boot/kernel
KMODDIR=	/boot/modules

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

.if ${OSVERSION} < 600000
IGNORE=		FreeBSD before 6.0 is not supported
.elif ${OSVERSION} > 700000
IGNORE=		FreeBSD 7.0 has an ipmi driver supplied by the kernel
.endif

do-install:
	@${MKDIR} ${PREFIX}/include/sys
	${INSTALL_SCRIPT} ${WRKSRC}/sys/ipmi.h ${PREFIX}/include/sys
	${INSTALL_SCRIPT} ${WRKSRC}/ipmi.ko ${KMODDIR}

.include <bsd.port.post.mk>
