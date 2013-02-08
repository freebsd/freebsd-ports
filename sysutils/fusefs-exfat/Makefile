# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	exfat
PORTVERSION=	1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fuse-${PORTNAME}-${PORTVERSION}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Full-featured exFAT FS implementation as a FUSE module

LICENSE=	GPLv3

LIB_DEPENDS=	ublio:${PORTSDIR}/devel/libublio

USE_FUSE=	yes
USE_ICONV=	yes
USE_SCONS=	yes

MAN8=		mount.exfat-fuse.8
PLIST_FILES=	bin/mount.exfat-fuse bin/mount.exfat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fuse/mount.exfat-fuse ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/mount.exfat-fuse ${PREFIX}/bin/mount.exfat
	${INSTALL_MAN} ${WRKSRC}/fuse/${MAN8} ${MAN8PREFIX}/man/man8

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' ${WRKSRC}/SConstruct

.include <bsd.port.mk>
