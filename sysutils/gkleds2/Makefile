# New ports collection makefile for:	gkleds2
# Date Created:		Dec 10 2002
# Whom:			Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	gkleds2
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://heim.ifi.uio.no/~oyvinha/files/files/
DISTNAME=	gkleds-${PORTVERSION}

MAINTAINER=	Jan.Stocker@t-online.de
COMMENT=	GKrellM Leds for CapsLock, NumLock and ScrollLock

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAKE_ENV+=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins \
		INSTALL_PROG="${INSTALL_PROGRAM}"

.include <bsd.port.mk>
