# New ports collection makefile for: net-p2p/eiskaltdc
# Date created:		28 Aug 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	eiskaltdc
PORTVERSION=	1.0.0
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	stast@bsdportal.ru
COMMENT=	A Direct Connect client QT GUI

LIB_DEPENDS=	dc.5:${PORTSDIR}/net-p2p/dclib

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network qt3support \
		moc_build uic_build rcc_build linguist_build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DCLIB_CFLAGS=-I${LOCALBASE}/include
QTCFGLIBS+=	${PTHREAD_LIBS}

.include <bsd.port.mk>
