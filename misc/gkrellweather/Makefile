# New ports collection makefile for:	gkrellweather
# Date Created:				Thu Jun 28 01:54:57 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
# With help from:	Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellweather
PORTVERSION=	0.2.7
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.cse.unsw.edu.au/~flam/repository/c/gkrellm/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	GKrellWeather is a weather plugin for GKrellM

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm \
		${X11BASE}/bin/GrabWeather:${PORTSDIR}/misc/wmweather

USE_X_PREFIX=	yes
USE_GNOME=	imlib
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
ALL_TARGET=	${PORTNAME}.so

PKGMESSAGE=	${DESCR}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.so \
		${PREFIX}/libexec/gkrellm/plugins

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
