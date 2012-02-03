# New ports collection makefile for:	dvdvideo
# Date created:			26 Jan 2012
# Whom:				Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	dvdvideo
PORTVERSION=	20120126
PORTREVISION=	1
CATEGORIES=	sysutils multimedia
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
DISTNAME=	python-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Video DVD backup tool

LICENSE=	GPLv3

USE_PYTHON=	3.1+
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	python_dvdvideo-0.1-py${PYTHON_VER}.egg-info

.if defined(PACKAGE_BUILDING)
DVDCSS_OPTION=	off
.else
DVDCSS_OPTION=	on
.endif

OPTIONS=	DVDCSS "Include libdvdcss support" ${DVDCSS_OPTION}

# DVDCSS version hardcoded in dvdvideo/libdvdcss.py
DVDCSS_LIBVERSION=	3

.include <bsd.port.pre.mk>

.if defined(WITH_DVDCSS)
LIB_DEPENDS+=	dvdcss.${DVDCSS_LIBVERSION}:${PORTSDIR}/multimedia/libdvdcss
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/dvdvideo/libdvdcss.py

.include <bsd.port.post.mk>
