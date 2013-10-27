# $FreeBSD$

PORTNAME=	kdehier4
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Hierarchy of shared directories for KDE 4 ports

NO_BUILD=	yes
USE_LDCONFIG=	${KDE4_PREFIX}/lib
USE_KDE4=	#

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${KDE4_PREFIX} != ${PREFIX}
PLIST_SUB+=	MTREE="" \
		LDCONFIG_DIR="${LDCONFIG_DIR}" \
		LDCONFIG32_DIR="${LDCONFIG32_DIR}"
SUB_FILES=	session-kde4.conf \
		system-kde4.conf
SUB_LIST=	KDE4_PREFIX="${KDE4_PREFIX}"
.else
PLIST_SUB+=	MTREE="@comment "
.endif

do-install:
	@for dir in `${GREP} -v "^@comment" ${FILESDIR}/dirlist`; \
	do \
		${MKDIR} ${KDE4_PREFIX}/$${dir}; \
	done
.if ${KDE4_PREFIX} != ${PREFIX}
	@for dir in `${GREP} -v "^@comment" ${FILESDIR}/mtree-dirlist`; \
	do \
		${MKDIR} ${KDE4_PREFIX}/$${dir}; \
	done
	${MKDIR} ${PREFIX}/etc/dbus-1
	${INSTALL_DATA} ${WRKDIR}/session-kde4.conf ${PREFIX}/etc/dbus-1
	${INSTALL_DATA} ${WRKDIR}/system-kde4.conf ${PREFIX}/etc/dbus-1
. for dir in pam.d polkit-1 rc.d
	${LN} -sf ${PREFIX}/etc/${dir} ${KDE4_PREFIX}/etc/
. endfor
	${LN} -sf ${PREFIX}/${LDCONFIG_DIR} ${KDE4_PREFIX}/libdata/
	${LN} -sf ${PREFIX}/${LDCONFIG32_DIR} ${KDE4_PREFIX}/libdata/
	${LN} -sf ${PREFIX}/libdata/pkgconfig ${KDE4_PREFIX}/libdata/
. for dir in services system-services
	${LN} -sf ${PREFIX}/share/dbus-1/${dir} ${KDE4_PREFIX}/share/dbus-1/
. endfor
	${LN} -sf ${PREFIX}/share/polkit-1/actions ${KDE4_PREFIX}/share/polkit-1/
.endif

maintainer-generate-plist:
	cd ${FILESDIR} && ${SH} make-plist.sh

.include <bsd.port.post.mk>
