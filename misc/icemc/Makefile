# New ports collection makefile for:	icemc
# Date created:				31 December 2001
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	icemc
PORTVERSION=	0.2.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.mittendorfer.com/gm/comp/icemc/

MAINTAINER=	monkey@crackula.com

USE_X_PREFIX=	yes
USE_QT_VER=	2

MAKE_ENV=	QTCPPFLAGS="${QTCPPFLAGS}" QTCFGLIBS="${QTCFGLIBS}" \
		MOC="${MOC}" LIBQT="-l${QTNAME}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/icemc ${PREFIX}/bin

.include <bsd.port.mk>
