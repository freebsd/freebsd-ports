# New ports collection makefile for:	gkrellweather2
# Date Created:		24 Nov 2002
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gkrellweather
PORTVERSION=	2.0.7
PORTREVISION=	6
CATEGORIES=	misc geography
MASTER_SITES=	http://makovick.googlepages.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pav@FreeBSD.org
COMMENT=	GKrellWeather is a weather plugin for GKrellM

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_GMAKE=	yes
ALL_TARGET=	gkrellweather.so

MAKE_ENV=	enable_nls=1 PTHREAD_LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

# uses C99 builtin lrintf
.if ${ARCH} != "amd64"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-lrintf
.endif

do-install:
	${MKDIR} ${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_DATA} ${WRKSRC}/gkrellweather.so ${PREFIX}/libexec/gkrellm2/plugins
	${MKDIR} ${PREFIX}/share/locale/ru/
	${INSTALL_DATA} ${WRKSRC}/po/ru.mo ${PREFIX}/share/locale/ru/LC_MESSAGES/gkrellweather.mo
	${INSTALL_SCRIPT} ${WRKSRC}/GrabWeather ${PREFIX}/bin

.include <bsd.port.post.mk>
