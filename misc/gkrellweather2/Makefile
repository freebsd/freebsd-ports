# New ports collection makefile for:	gkrellweather2
# Date Created:		24 Nov 2002
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
# $Id: Makefile,v 1.1.1.1 2002/11/24 03:13:54 jylefort Exp $
#

PORTNAME=	gkrellweather
PORTVERSION=	2.0.5
CATEGORIES=	misc
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jylefort@brutele.be

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2 \
		${X11BASE}/bin/GrabWeather:${PORTSDIR}/misc/wmweather

USE_X_PREFIX=	yes

MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
