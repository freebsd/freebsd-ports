PORTNAME=	acfgfs
DISTVERSION=	0.6.3.2
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	FUSE file system driver for Arcan window managers
WWW=		https://arcan-fe.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC:H:H:H}/data/distr/LICENSE.BSD

LIB_DEPENDS=	libarcan_shmif_ext.so:multimedia/arcan

USES=		cmake compiler:c11 fuse:3 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	letoram
GH_PROJECT=	arcan
WRKSRC_SUBDIR=	src/tools/${PORTNAME}
PLIST_FILES=	bin/arcan_cfgfs \
		share/man/man1/arcan_cfgfs.1.gz

.include <bsd.port.mk>
