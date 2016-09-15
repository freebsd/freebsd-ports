# Created by: leres
# $FreeBSD$

PORTNAME=	procps
PORTVERSION=	3.2.7
CATEGORIES=	sysutils linux
PKGNAMEPREFIX=	linux-f10-

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux psproc binaries (Linux Fedora 10)

CONFLICTS=	linux-procps-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
RPMVERSION=	21.fc10
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

PROCFS=	/compat/linux/proc

post-install:
	@df ${PROCFS} 2>&1 | ${EGREP} '^linprocfs ' > /dev/null 2>&1 || (echo ">>>" ; echo ">>> You still need to mount ${PROCFS}; see linprocfs(5)" ; echo ">>> for more information" ; echo ">>>")

.include <bsd.port.mk>
