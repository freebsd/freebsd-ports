# Created by: Franz Bettag <franz@bett.ag>
# $FreeBSD$

PORTNAME=	pixiewps
PORTVERSION=	1.2.2
DISTVERSIONPREFIX= v
CATEGORIES=	security

MAINTAINER=	franz@bett.ag
COMMENT=	Offline WPS bruteforce utility

LICENSE=	GPLv3

USE_OPENSSL=	yes

USES=		gmake
WRKSRC_SUBDIR=	src/
USE_GITHUB=	yes
GH_ACCOUNT=	wiire

PLIST_FILES=	bin/pixiewps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
