# New ports collection makefile for:	gkrellmmultiping2
# Date Created:		24 Nov 2002
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
# $Id: Makefile,v 1.1.1.1 2002/11/24 23:19:28 jylefort Exp $
#

PORTNAME=	gkrellmmultiping
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
DISTNAME=	gkrellm-multiping-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM multiping plugin

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_X_PREFIX=	yes
USE_REINPLACE=	yes

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		CHMOD="${CHMOD}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.pre.mk>

post-patch:
		${REINPLACE_CMD} -e \
		"s,@COMMAND@,${PREFIX}/libexec/gkrellm2/plugins/pinger," \
		${WRKSRC}/multiping.c

.include <bsd.port.post.mk>
