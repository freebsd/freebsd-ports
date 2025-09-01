PORTNAME=	rclone
DISTVERSIONPREFIX=	v
DISTVERSION=	1.71.0
CATEGORIES=	net

MAINTAINER=	tremere@cainites.net
COMMENT=	Sync files to and from various cloud services
WWW=		https://rclone.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfuse.so:filesystems/fusefs-libs
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:modules
GO_MODULE=	github.com/rclone/rclone

GO_BUILDFLAGS=	-ldflags -s -tags cmount

PLIST_FILES=	bin/rclone \
		share/man/man1/rclone.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/rclone.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
