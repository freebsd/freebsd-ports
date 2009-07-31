# New ports collection makefile for:	gkrellflynn
# Date Created:				Fri Aug 17 15:57:42 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellflynn
PORTVERSION=	0.8
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		http://horus.comlab.uni-rostock.de/flynn/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A tiny system load meter for gkrellm

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellflynn.so
USE_GNOME=	gtk20
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -c -fPIC"
ALL_TARGET=	${PORTNAME}.so

CFLAGS+=	`pkg-config --cflags gtk+-2.0 gthread-2.0` \
		-I${LOCALBASE}/include -DGKRELLM2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellflynn.so \
		${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
