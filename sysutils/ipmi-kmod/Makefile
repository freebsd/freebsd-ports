# Ports collection makefile for: ipmi-kmod
# Date created: 18 April 2006
# Whom:         Nick Barkas <snb@threerings.net>
#
# $FreeBSD$
#

PORTNAME=	ipmi-kmod
PORTVERSION=	20060926
PORTREVISION=	1
CATEGORIES=	sysutils kld
MASTER_SITES=	http://dpw.threerings.net/projects/ipmi-kmod/

MAINTAINER=	snb@FreeBSD.org
COMMENT=	Backport of ipmi driver from FreeBSD 7-CURRENT for FreeBSD 5.3 - 6.1

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	KMODDIR=${KMODDIR}

PLIST_FILES=	include/sys/ipmi.h \
		"@dirrm include/sys" \
		"@cwd /" \
		${KMODDIR:C,^/,,}/ipmi.ko \

# We want to install the module in /boot/modules rather than /boot/kernel
KMODDIR=	/boot/modules

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

.if exists(${SRC_BASE}/sys/dev/ipmi)
IGNORE=		is already included in the base system
.endif

do-install:
	@${MKDIR} ${PREFIX}/include/sys
	${INSTALL_DATA} ${WRKSRC}/sys/ipmi.h ${PREFIX}/include/sys
	${INSTALL_KLD} ${WRKSRC}/ipmi.ko ${KMODDIR}

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
