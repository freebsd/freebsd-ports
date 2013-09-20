# Created by: leres
# $FreeBSD$

PORTNAME=	procps
PORTVERSION=	3.2.7
CATEGORIES=	sysutils linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}.fc${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux psproc binaries (Linux Fedora 10)

CONFLICTS=	linux-procps-[0-9]*

USE_LINUX_RPM=	yes
ONLY_FOR_ARCHS=	i386 amd64
LINUX_DIST_VER=	10
RPMVERSION=	21
USE_LDCONFIG=	yes
BRANDELF_DIRS=	bin sbin usr/bin
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

PROCFS= /compat/linux/proc

NO_STAGE=	yes
post-install:
	@df ${PROCFS} 2>&1 | ${EGREP} '^linprocfs ' > /dev/null 2>&1 || (echo ">>>" ; echo ">>> You still need to mount ${PROCFS}; see linprocfs(5)" ; echo ">>> for more information" ; echo ">>>")

.include <bsd.port.mk>
