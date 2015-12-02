# Created by: Franz Bettag <franz@bett.ag>
# $FreeBSD$

PORTNAME=	pixiewps
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	https://github.com/wiire/pixiewps/

MAINTAINER=	franz@bett.ag
COMMENT=	Offline WPS bruteforce utility

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	wiire
GH_TAGNAME=	08a78c3c

USE_OPENSSL=	yes

USES=	gmake
WRKSRC_SUBDIR=	src/

PLIST_FILES=	bin/pixiewps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
