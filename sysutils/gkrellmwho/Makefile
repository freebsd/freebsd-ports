# New ports collection makefile for:	gkrellmwho
# Date Created:				11.August 2002
# Whom:					Steffen Vogelreuter
#
# $FreeBSD$
#

PORTNAME=	gkrellmwho
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/Plugins/

MAINTAINER=	steffen@vogelreuter.de
COMMENT=	A plugin that scrolls in a panel a list of currently logged on users

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_X_PREFIX=	yes
USE_GNOME=	imlib
USE_GMAKE=	yes
ALL_TARGET=	#empty

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gkrellmwho.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
