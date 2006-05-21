# New ports collection makefile for:	jaffm
# Date Created:				2006-04-27
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	jaffm
PORTVERSION=	1.3.1
CATEGORIES=	x11-fm
MASTER_SITES=	http://binary.is/download/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/

MAINTAINER=	shaun@inerd.com
COMMENT=	A lightweight file manager inspired by MacOS Finder

WXGTK_VER?=	2.6

USE_BZIP2=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${WXGTK_VER} == "2.4" || \
    (exists(${X11BASE}/bin/wxgtk2-2.4-config) && \
    !exists(${X11BASE}/bin/wxgtk2-2.6-config))
LIB_DEPENDS+=	wx_gtk2_core-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24
WXGTK_VER=	2.4
.else
LIB_DEPENDS+=	wx_gtk2_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26
WXGTK_VER=	2.6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#^PREFIX=.*#PREFIX=${PREFIX}#' \
		-e 's#$$(shell wx-config \(.*\))#`${X11BASE}/bin/wxgtk2-${WXGTK_VER}-config \1`#' \
		-e 's#^FLAGS=-ggdb#FLAGS=${CFLAGS}#' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
