# $FreeBSD$

PORTNAME=	kdehier4
PORTVERSION=	1.3
CATEGORIES=	misc kde
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Meta port to organize KDE4_PREFIX

NO_BUILD=	yes
USE_KDE4=	#

DEPRECATED=	Not used since 2014
EXPIRATION_DATE=2016-03-09

.include <bsd.port.pre.mk>

.if ${KDE4_PREFIX} != ${PREFIX}
USE_LDCONFIG=	${KDE4_PREFIX}/lib
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
.if ${KDE4_PREFIX} != ${PREFIX}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/dbus-1
	${INSTALL_DATA} ${WRKDIR}/session-kde4.conf ${STAGEDIR}${PREFIX}/etc/dbus-1
	${INSTALL_DATA} ${WRKDIR}/system-kde4.conf ${STAGEDIR}${PREFIX}/etc/dbus-1
	${MKDIR} ${STAGEDIR}${KDE4_PREFIX}/etc
. for dir in pam.d polkit-1 rc.d
	${LN} -sf ${PREFIX}/etc/${dir} ${STAGEDIR}${KDE4_PREFIX}/etc/
. endfor
	${MKDIR} ${STAGEDIR}${KDE4_PREFIX}/libdata
	${LN} -sf ${PREFIX}/${LDCONFIG_DIR} ${STAGEDIR}${KDE4_PREFIX}/libdata/
	${LN} -sf ${PREFIX}/${LDCONFIG32_DIR} ${STAGEDIR}${KDE4_PREFIX}/libdata/
	${LN} -sf ${PREFIX}/libdata/pkgconfig ${STAGEDIR}${KDE4_PREFIX}/libdata/
	${MKDIR} ${STAGEDIR}${KDE4_PREFIX}/share/dbus-1
. for dir in services system-services
	${LN} -sf ${PREFIX}/share/dbus-1/${dir} ${STAGEDIR}${KDE4_PREFIX}/share/dbus-1/
. endfor
	${MKDIR} ${STAGEDIR}${KDE4_PREFIX}/share/polkit-1/
	${LN} -sf ${PREFIX}/share/polkit-1/actions ${STAGEDIR}${KDE4_PREFIX}/share/polkit-1/
.endif

.include <bsd.port.post.mk>
