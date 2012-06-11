# New ports collection makefile for:	dvdvideo
# Date created:			26 Jan 2012
# Whom:				Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	dvdvideo
PORTVERSION=	20120126
PORTREVISION=	3
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

OPTIONS_DEFINE=	DVDCSS
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	DVDCSS
.endif

# DVDCSS version hardcoded in dvdvideo/libdvdcss.py
DVDCSS_LIBVERSION=	3

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 323
BROKEN=	bad plist with latest python
.endif

.if ${PORT_OPTIONS:MDVDCSS}
LIB_DEPENDS+=	dvdcss:${PORTSDIR}/multimedia/libdvdcss
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/dvdvideo/libdvdcss.py

.include <bsd.port.post.mk>
