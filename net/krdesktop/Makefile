# New ports collection makefile for:	krdesktop
# Date created:		23 June 2002
# Whom:			Matt Douhan <matt@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	krdesktop
PORTVERSION=	1.8
PORTREVISION=	3
CATEGORIES=	net kde
MASTER_SITES=	http://www.fruitsalad.org/people/mdouhan/krdesktop/
DISTNAME=	${PORTNAME:S/kr/KR/}-${PORTVERSION}

MAINTAINER=	matt@fruitsalad.org
COMMENT=	KDE GUI for rdesktop and VNC

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop \
		vncviewer:${PORTSDIR}/net/vnc

USE_KDELIBS_VER=3
NO_WRKSUBDIR=   yes
PLIST_FILES=	bin/krdesktop

MAKE_ENV=       QTDIR=${QT_PREFIX} \
		KDEDIR=${LOCALBASE} \
		MOC=${MOC}

CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include <bsd.port.mk>
