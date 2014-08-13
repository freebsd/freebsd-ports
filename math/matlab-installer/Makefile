# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: head/math/matlab-installer/Makefile 363395 2014-07-29 21:25:30Z adamw $

PORTNAME=	matlab-installer
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	math science java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Easy installation of Linux Matlab(r) on FreeBSD

LICENSE=	BSD

# Move devtools depend to USE_LINUX_APPS when possible
RUN_DEPENDS=	mount_cd9660_image:${PORTSDIR}/sysutils/diskimage-tools \
		auto-ask:${PORTSDIR}/sysutils/auto-admin \
		webbrowser:${PORTSDIR}/www/webbrowser \
		${LINUXBASE}/usr/bin/gfortran:${PORTSDIR}/devel/linux-f10-devtools

USES=		tar:xz
USE_LINUX=	yes
USE_LINUX_APPS=	ncurses-base dri
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	linux
JAVA_RUN=	yes

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/matlab-installer.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
