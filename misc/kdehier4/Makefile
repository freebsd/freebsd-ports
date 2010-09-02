# New ports collection makefile for:	kdehier4
# Date created:		2008-07-03
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kdehier4
PORTVERSION=	1.0.6
CATEGORIES=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Utility port that creates hierarchy of shared KDE4 directories

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_KDE4=	kdeprefix

.include <bsd.port.pre.mk>

.if ${KDE4_PREFIX} != ${LOCALBASE}
PLIST_SUB+=	MTREE="" \
		LDCONFIG_DIR="${LDCONFIG_DIR}" \
		LDCONFIG32_DIR="${LDCONFIG32_DIR}"
SUB_FILES=	session-kde4.conf \
		system-kde4.conf
SUB_LIST=	KDE4_PREFIX="${KDE4_PREFIX}"
.else
PLIST_SUB+=	MTREE="@comment "
.endif

do-fetch:
	@${DO_NADA}

do-install:
	@for dir in `${GREP} -v "^@comment" ${FILESDIR}/dirlist`; \
	do \
		${MKDIR} ${PREFIX}/$${dir}; \
	done
.if ${KDE4_PREFIX} != ${LOCALBASE}
	@for dir in `${GREP} -v "^@comment" ${FILESDIR}/mtree-dirlist`; \
	do \
		${MKDIR} ${PREFIX}/$${dir}; \
	done
	${LN} -sf ${LOCALBASE}/${LDCONFIG_DIR} ${KDE4_PREFIX}/libdata/
	${LN} -sf ${LOCALBASE}/${LDCONFIG32_DIR} ${KDE4_PREFIX}/libdata/
	${LN} -sf ${LOCALBASE}/libdata/pkgconfig ${KDE4_PREFIX}/libdata/
	${LN} -sf ${LOCALBASE}/share/PolicyKit/policy ${KDE4_PREFIX}/share/PolicyKit/
	${ECHO_CMD} ${KDE4_PREFIX}/lib > \
		${LOCALBASE}/${LDCONFIG_DIR}/kdehier4
	${MKDIR} ${LOCALBASE}/etc/dbus-1
	${INSTALL_DATA} ${WRKDIR}/session-kde4.conf ${LOCALBASE}/etc/dbus-1
	${INSTALL_DATA} ${WRKDIR}/system-kde4.conf ${LOCALBASE}/etc/dbus-1
.endif

maintainer-generate-plist:
	cd ${FILESDIR} && ${SH} make-plist.sh

.include <bsd.port.post.mk>
