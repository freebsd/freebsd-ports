# New ports collection makefile for:	linux-procps
# Date created:				2007-04-04
# Whom:					leres
#
# $FreeBSD$
#

PORTNAME=	procps
PORTVERSION=	3.2.5
CATEGORIES=	sysutils linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	${PORTNAME}-${PORTVERSION}-6.4

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux psproc binaries

USE_LINUX_RPM=	yes
ONLY_FOR_ARCHS=	i386 amd64
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
BRANDELF_DIRS=	bin sbin usr/bin
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

PROCFS= /compat/linux/proc

post-install:
	@df ${PROCFS} 2>&1 | ${EGREP} '^linprocfs ' > /dev/null 2>&1 || (echo ">>>" ; echo ">>> You still need to mount ${PROCFS}; see linprocfs(5)" ; echo ">>> for more information" ; echo ">>>")

.include <bsd.port.mk>
