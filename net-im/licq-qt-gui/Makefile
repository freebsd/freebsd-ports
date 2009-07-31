# New ports collection makefile for:    qt-gui-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael272home.com>
#
# $FreeBSD$
#

PORTNAME=	qt-gui
PORTVERSION=	${QT_LICQ_VER}
PORTREVISION=	1
CATEGORIES=	net-im
PKGNAMESUFFIX?=	${KDE_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Qt plugin for licq

LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost-libs

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
LICQ_PORT?=	net-im/licq

.if defined(WITH_KDE)
KDE_SUFFIX=	-kde
USE_KDELIBS_VER=3
CONFIGURE_ARGS+=--with-kde
CONFIGURE_ENV+=	KDEDIR="${LOCALBASE}"
PLIST_SUB+=	GUI_NAME=kde
PLIST_SUB+=	WITH_KDE=""
PLIST_SUB+=	WITH_QT="@comment "
.else
USE_QT_VER=	3
PLIST_SUB+=	GUI_NAME=qt
PLIST_SUB+=	WITH_KDE="@comment "
PLIST_SUB+=	WITH_QT=""
.endif

pre-fetch:
.if defined(WITH_KDE)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Build with KDE support"
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You could define WITH_KDE if you want KDE support"
	@${ECHO_MSG} ""
.endif

post-patch:
	${RM} -f ${WRKDIR}/share/qt-gui/icons.thomas/icons.thomas.tar.bz2

post-install:
#	${RM} -rf ${PREFIX}/share/licq/qt-gui/locale
.if exists(${LOCALBASE}/bin/XFree86)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"
.include <bsd.port.post.mk>
