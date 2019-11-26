# $FreeBSD$

PORTNAME=	matlab-installer
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	math science java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Easy installation of Linux Matlab(r) on FreeBSD

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	mount_cd9660_image:sysutils/diskimage-tools \
		auto-ask:sysutils/auto-admin \
		webbrowser:www/webbrowser \

USES=		linux tar:xz
USE_LINUX=	dri devtools
USE_JAVA=	yes
JAVA_OS=	linux
JAVA_RUN=	yes

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/matlab-installer.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
