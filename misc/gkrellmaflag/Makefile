# New ports collection makefile for:	gkrellmaflag
# Date Created:				Tue Sep 25 20:01:10 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	aflag
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.geocities.com/saintdead/
PKGNAMEPREFIX=	gkrellm
DISTNAME=	${PORTNAME}_anim-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A GKrellM Plugin that displays a waving American flag

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_GNOME=	imlib
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
ALL_TARGET=	${PORTNAME}_anim.so

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}_anim.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
