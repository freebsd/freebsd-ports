# New ports collection makefile for:	gkrellmqst
# Date Created:				Thu Jun 28 01:54:57 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
# With help from:	Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmqst
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	net games
MASTER_SITES=	http://tadpol.org/projects/binaries/
DISTNAME=	gkrellm_qst-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Plugin for Gkrellm that displays updated info on several game servers

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm \
		qstat:${PORTSDIR}/games/qstat

PLIST_FILES=	libexec/gkrellm/plugins/qst.so
WRKSRC=		${WRKDIR}/${PORTNAME:S/mq/m_q/}
USE_X_PREFIX=	yes
USE_GNOME=	imlib
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
ALL_TARGET=	qst.so

.include <bsd.port.mk>
