# New ports collection makefile for:	gkrellmmultiping2
# Date Created:		24 Nov 2002
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gkrellmmultiping
PORTVERSION=	2.0.10
CATEGORIES=	net
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/ \
		http://depot.fsck.ch/mirror/distfiles/
DISTNAME=	gkrellm-multiping-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@fsck.ch
COMMENT=	GKrellM2 multiping plugin

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_X_PREFIX=	yes
PLIST_FILES=	libexec/gkrellm2/plugins/multiping.so libexec/gkrellm2/plugins/pinger

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		CHMOD="${CHMOD}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
