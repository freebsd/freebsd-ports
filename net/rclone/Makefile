PORTNAME=	rclone
DISTVERSIONPREFIX=	v
DISTVERSION=	1.59.0
CATEGORIES=	net

MAINTAINER=	tremere@cainites.net
COMMENT=	Sync files to and from various cloud services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:modules
GO_MODULE=	github.com/rclone/rclone

PLIST_FILES=	bin/rclone \
		man/man1/rclone.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/rclone.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
