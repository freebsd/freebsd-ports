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
COMMENT=	Backport of ipmi driver from FreeBSD 7-CURRENT for FreeBSD 5.x/6.x

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

.if exists(/usr/include/sys/ipmi.h)
IGNORE=		already in the base system
.elif ${OSVERSION} < 503000
IGNORE=		does not support FreeBSD before 5.3
.endif

do-install:
	@${MKDIR} ${PREFIX}/include/sys
	${INSTALL_DATA} ${WRKSRC}/sys/ipmi.h ${PREFIX}/include/sys
	${INSTALL_PROGRAM} ${WRKSRC}/ipmi.ko ${DESTDIR}${KMODDIR}

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
