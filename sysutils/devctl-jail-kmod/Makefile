PORTNAME=	devctl-jail-kmod
DISTVERSION=	g20230518
CATEGORIES=	sysutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Module to expose jail lifecycle events

LICENSE=	BSD-2-Clause BSD-3-Clause
LICENSE_COMB= multi
LICENSE_FILE_BSD-2-Clause=    ${WRKSRC}/devctl.h
LICENSE_FILE_BSD-3-Clause=    ${WRKSRC}/LICENSE

BROKEN_FreeBSD_15=	fails to build: sys/vnode.h requires the generated vnode_if.h
BROKEN_FreeBSD_16=	fails to build: sys/vnode.h requires the generated vnode_if.h

USES=	kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	fubarnetes
GH_PROJECT=	kmod_devctl_jail
GH_TAGNAME=	c5a9a4abe24

PLIST_FILES=	${KMODDIR}/devctl_jail.ko \
		"@dir /%%KMODDIR%%"

.include <bsd.port.mk>
