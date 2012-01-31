# New ports collection makefile for:	fusefs-exfat
# Date created:				2012-01-25
# Whom:					Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	exfat
PORTVERSION=	0.9.6
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fuse-${PORTNAME}-${PORTVERSION}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	A full-featured exFAT FS implementation as a FUSE module

LICENSE=	GPLv3

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_ICONV=	yes
USE_SCONS=	yes
SCONS_ENV+=	LIBPATH=${PREFIX}/lib
SCONS_BUILDENV=	${SCONS_ENV} CXXFLAGS=" -I${LOCALBASE}/include " \
		LDFLAGS=" -L${LOCALBASE}/lib "
SCONS_ARGS+=	prefix=${PREFIX} use_env=1

MAN8=		mount.exfat-fuse.8
PLIST_FILES=	bin/mount.exfat-fuse bin/mount.exfat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fuse/mount.exfat-fuse ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/mount.exfat-fuse ${PREFIX}/bin/mount.exfat
	${INSTALL_MAN} ${WRKSRC}/fuse/${MAN8} ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
