# $FreeBSD$

PORTNAME=	diskimage-tools
DISTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Convenience tools for manipulating disk images

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:xz

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/mount_image \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/umount_image \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/img2dev \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/mount_image.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/umount_image.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/img2dev.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
