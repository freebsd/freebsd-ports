# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	diskimage-tools
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Convenience tools for manipulating disk images

LICENSE=	BSD

NO_BUILD=	yes
USES=		tar:xz

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/mount_cd9660_image \
		${WRKSRC}/umount_cd9660_image ${WRKSRC}/img2dev \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/mount_cd9660_image.1 \
		${WRKSRC}/umount_cd9660_image.1 ${WRKSRC}/img2dev.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
