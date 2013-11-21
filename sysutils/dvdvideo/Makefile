# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	dvdvideo
PORTVERSION=	20130117
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
PYDISTUTILS_EGGINFO=	python_dvdvideo-0.${PORTVERSION}-py${PYTHON_VER}.egg-info

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

OPTIONS_DEFINE=	DVDCSS
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	DVDCSS
.endif
DVDCSS_LIB_DEPENDS=	libdvdcss.so:${PORTSDIR}/multimedia/libdvdcss

# DVDCSS version hardcoded in dvdvideo/libdvdcss.py
DVDCSS_LIBVERSION=	3

post-patch:
	@${REINPLACE_CMD} -E 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/dvdvideo/libdvdcss.py

.include <bsd.port.mk>
