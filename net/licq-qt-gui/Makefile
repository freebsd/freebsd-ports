# New ports collection makefile for:    qt-gui-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael272home.com>
#
# $FreeBSD$
#

PORTNAME=	qt-gui
PORTVERSION=	${QT_LICQ_VER}
CATEGORIES=	net

MAINTAINER=	dinoex@FreeBSD.org

USE_QT_VER=	3
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
INCDIR=		${PORTSDIR}/net

post-install:
	${RM} -rf ${PREFIX}/share/licq/qt-gui/locale
.if exists(${X11BASE}/bin/XFree86)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>
.include "${INCDIR}/licq/Makefile.inc"
.include <bsd.port.post.mk>
