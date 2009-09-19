# New ports collection makefile for:	di
# Date created:			31 August 2002
# Whom:				Brad Lanam <bll@gentoo.com>
#
# $FreeBSD$
#

PORTNAME=	di
PORTVERSION=	4.15
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gentoo.com/di/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Disk Information Utility

MAN1=		di.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
DI_BUILD_NO_NLS=	0
.else
DI_BUILD_NO_NLS=	1
PLIST_SUB=	NLS="@comment "
.endif

USE_PERL5_BUILD=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|zoneid_t|zoneId_t|g" ${WRKSRC}/di.c

pre-configure:
	@${CHMOD} +x ${WRKSRC}/Build
	@${CHMOD} +x ${WRKSRC}/features/turnoffnls.sh

do-configure:
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} DI_BUILD_MKCONFIG_PL=1 \
		CC="${CC}" LDFLAGS="${LDFLAGS}" \
		prefix="${PREFIX}" LOCALEDIR="${PREFIX}/share/locale" \
		DI_BUILD_NO_NLS=${DI_BUILD_NO_NLS} \
		./Build config.h)

post-configure:
	@${REINPLACE_CMD} -e "s|#define _lib_zone_list 1|#undef _lib_zone_list|" ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e "s|#define _lib_fs_stat_dev 1|#undef _lib_fs_stat_dev|" ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e "s|#define _lib_getvfsstat 1|#undef _lib_getvfsstat|" ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e "s|#define _lib_getmnt 1|#undef _lib_getmnt|" ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e "s|#define _lib_mntctl 1|#undef _lib_mntctl|" ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e "s|#define _lib_GetDiskFreeSpace 1|#undef _lib_GetDiskFreeSpace|" ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e "s|#define _lib_GetDriveType 1|#undef _lib_GetDriveType|" ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e "s|#define _lib_GetLogicalDriveStrings 1|#undef _lib_GetLogicalDriveStrings|" ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e "s|#define _lib_GetVolumeInformation 1|#undef _lib_GetVolumeInformation|" ${WRKSRC}/config.h

do-build:
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} \
		CC="${CC}" LDFLAGS="${LDFLAGS}" \
		prefix="${PREFIX}" LOCALEDIR="${PREFIX}/share/locale" \
		DI_BUILD_NO_NLS=${DI_BUILD_NO_NLS} \
		./Build)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/di ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/di ${PREFIX}/bin/mi
	${INSTALL_MAN} ${WRKSRC}/di.1 ${PREFIX}/man/man1
.if !defined(WITHOUT_NLS)
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} \
		CC="${CC}" LDFLAGS="${LDFLAGS}" \
		prefix="${PREFIX}" \
		LOCALEDIR="${PREFIX}/share/locale" \
		./Build build-po)
	-(cd ${WRKSRC}/po;for i in *.po; do \
	j=`echo $$i | ${SED} 's,\\.po$$,,'`; \
	test -d ${PREFIX}/share/locale/$$j || \
		${MKDIR} ${PREFIX}/share/locale/$$j; \
	test -d ${PREFIX}/share/locale/$$j/LC_MESSAGES || \
		${MKDIR} ${PREFIX}/share/locale/$$j/LC_MESSAGES; \
	${INSTALL_DATA} $$j.mo \
	${PREFIX}/share/locale/$$j/LC_MESSAGES/di.mo; \
	${RM} -f $$j.mo; \
	done)
.endif

.include <bsd.port.post.mk>
