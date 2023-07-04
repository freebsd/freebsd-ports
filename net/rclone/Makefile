PORTNAME=	rclone
DISTVERSIONPREFIX=	v
DISTVERSION=	1.63.0
CATEGORIES=	net

MAINTAINER=	tremere@cainites.net
COMMENT=	Sync files to and from various cloud services
WWW=		https://rclone.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:modules
GO_MODULE=	github.com/rclone/rclone

GO_BUILDFLAGS=	-ldflags -s

PLIST_FILES=	bin/rclone \
		man/man1/rclone.1.gz

OPTIONS_DEFINE=	CMOUNT

CMOUNT_DESC=	Enable cmount command (depends on fusefs-libs)

CMOUNT_LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs
CMOUNT_VARS=		GO_BUILDFLAGS+="-tags cmount"

post-install:
	${INSTALL_MAN} ${WRKSRC}/rclone.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
