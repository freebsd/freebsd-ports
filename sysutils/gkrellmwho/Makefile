# New ports collection makefile for:	gkrellmwho
# Date Created:				11.August 2002
# Whom:					Steffen Vogelreuter
#
# $FreeBSD$
#

PORTNAME=	gkrellmwho
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/Plugins/

MAINTAINER=	steffen@vogelreuter.de

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib
USE_GMAKE=	yes
ALL_TARGET=	#empty

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gkrellmwho.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
