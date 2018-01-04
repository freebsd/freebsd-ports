# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	dvdvideo
PORTVERSION=	20130117
PORTREVISION=	2
CATEGORIES=	sysutils multimedia
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Video DVD backup tool

LICENSE=	GPLv3

NO_ARCH=	yes
USES=		python:3.4+ tar:tgz
USE_PYTHON=	autoplist distutils optsuffix

OPTIONS_DEFINE=	DVDCSS
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	DVDCSS
.endif
# DVDCSS version hardcoded in dvdvideo/libdvdcss.py
DVDCSS_LIB_DEPENDS=	libdvdcss.so.2:multimedia/libdvdcss

.include <bsd.port.mk>
