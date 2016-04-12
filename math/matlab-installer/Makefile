# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	matlab-installer
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	math science java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Easy installation of Linux Matlab(r) on FreeBSD

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	mount_cd9660_image:sysutils/diskimage-tools \
		auto-ask:sysutils/auto-admin \
		webbrowser:www/webbrowser \

USES=		tar:xz
USE_LINUX=	yes
USE_LINUX_APPS=	ncurses-base dri devtools
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
