# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	exfat
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fuse-${PORTNAME}-${PORTVERSION}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Full-featured exFAT FS implementation as a FUSE module

LICENSE=	Microsoft-exFAT
LICENSE_NAME=	Microsoft exFAT License
LICENSE_TEXT=	Requires license from Microsoft, please see \
		http://www.microsoft.com/en-us/legal/intellectualproperty/IPLicensing/Programs/exFATFileSystem.aspx
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

LIB_DEPENDS=	libublio.so:devel/libublio

USES=		fuse iconv scons

PLIST_FILES=	bin/mount.exfat-fuse bin/mount.exfat man/man8/mount.exfat-fuse.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fuse/mount.exfat-fuse ${STAGEDIR}${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/mount.exfat-fuse ${STAGEDIR}${PREFIX}/bin/mount.exfat
	${INSTALL_MAN} ${WRKSRC}/fuse/mount.exfat-fuse.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' ${WRKSRC}/SConstruct

.include <bsd.port.mk>
