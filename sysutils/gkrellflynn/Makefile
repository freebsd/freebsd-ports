# New ports collection makefile for:	gkrellflynn
# Date Created:				Fri Aug 17 15:57:42 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellflynn
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://horus.comlab.uni-rostock.de/flynn/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Flynn is a tiny system load meter for gkrellm

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_GNOME=	imlib
USE_X_PREFIX=	yes
ALL_TARGET=	${PORTNAME}.so

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gkrellflynn.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
