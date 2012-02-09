# New ports collection makefile for:	fusefs-exfat
# Date created:				2012-01-25
# Whom:					Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	exfat
PORTVERSION=	0.9.6
PORTREVISION=	1
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
SCONS_BUILDENV=	${SCONS_ENV} CXXFLAGS=" -I${LOCALBASE}/include ${CCFLAGS}" \
		LDFLAGS=" -L${LOCALBASE}/lib ${LIBS}"
SCONS_ARGS+=	prefix=${PREFIX} use_env=1

OPTIONS=	UBLIO "Enable user space cache for improved speed" on

MAN8=		mount.exfat-fuse.8
PLIST_FILES=	bin/mount.exfat-fuse bin/mount.exfat

.include <bsd.port.pre.mk>

.if defined(WITH_UBLIO)
LIB_DEPENDS+=	ublio.1:${PORTSDIR}/devel/libublio
CCFLAGS=	-DUSE_UBLIO
LIBS+=		-lublio
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: FreeBSD does not have cache support for block devices. This will considerably reduce the performance of this application, please consider enabling the UBLIO option and following the indications in the post-installation message." | ${FMT}
	@${ECHO_MSG}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fuse/mount.exfat-fuse ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/mount.exfat-fuse ${PREFIX}/bin/mount.exfat
	${INSTALL_MAN} ${WRKSRC}/fuse/${MAN8} ${MAN8PREFIX}/man/man8

.include <bsd.port.post.mk>
