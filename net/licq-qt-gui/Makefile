# New ports collection makefile for:    qt-gui-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael272home.com>
#
# $FreeBSD$
#

PORTNAME=	qt-gui
PORTVERSION=	${QT_LICQ_VER}
PORTREVISION=	2
CATEGORIES=	net
.if defined(WITH_KDE)
PKGNAMESUFFIX=	-kde
.endif

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Qt plugin for licq

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
LICQ_PORT?=	${PORTSDIR}/net/licq

.if defined(WITH_KDE)
USE_KDELIBS_VER=3
CONFIGURE_ARGS+=--with-kde
CONFIGURE_ENV+=	KDEDIR="${LOCALBASE}"
PLIST_SUB+=	GUI_NAME=kde
.else
USE_QT_VER=	3
PLIST_SUB+=	GUI_NAME=qt
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

post-install:
	${RM} -rf ${PREFIX}/share/licq/qt-gui/locale
.if exists(${X11BASE}/bin/XFree86)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>
.include "${LICQ_PORT}/Makefile.inc"
.include <bsd.port.post.mk>
