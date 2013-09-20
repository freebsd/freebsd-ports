# Created by: thompsa@FreeBSD.org
# $FreeBSD$

PORTNAME=	fconfig
PORTVERSION=	20080329
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.openwrt.org/sources/ \
		http://andrzejekiert.ovh.org/software/fconfig/

MAINTAINER=	thompsa@FreeBSD.org
COMMENT=	Read and modify RedBoot embedded boot configuration

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
PLIST_FILES=	sbin/fconfig

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fconfig ${PREFIX}/sbin

.include <bsd.port.mk>
