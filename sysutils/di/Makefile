# Created by: Brad Lanam <bll@gentoo.com>

PORTNAME=	di
PORTVERSION=	4.50
CATEGORIES=	sysutils
MASTER_SITES=	SF/diskinfo-di

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Disk Information Utility

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	-e
MAKE_ENV=	prefix="${PREFIX}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_MAKE_ENV_OFF=	DI_NO_NLS=T

pre-install:
	@${STRIP_CMD} ${WRKSRC}/C/di

.include <bsd.port.mk>
