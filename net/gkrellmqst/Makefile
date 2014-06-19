# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	gkrellmqst
PORTVERSION=	0.4
PORTREVISION=	9
CATEGORIES=	net games
MASTER_SITES=	http://tadpol.org/projects/archives/ \
		http://freebsd.unixfreunde.de/sources/
DISTNAME=	gkrellm_qst-${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Plugin for Gkrellm that displays updated info on several game servers

DEPRECATED=	GKrellM 1.X is no longer being developed, consider using 2.X.
EXPIRATION_DATE=2014-06-30

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm \
		qstat:${PORTSDIR}/games/qstat

PLIST_FILES=	libexec/gkrellm/plugins/qst.so
WRKSRC=		${WRKDIR}/${PORTNAME:S/mq/m_q/}
USE_GNOME=	imlib
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
ALL_TARGET=	qst.so

NO_STAGE=	yes
.include <bsd.port.mk>
