# New ports collection makefile for:	gkrellmouse
# Date Created:				Fri Aug 17 15:57:42 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellmouse
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://ssl.usu.edu/paul/gkrellmouse/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Mouse odometer plugin for GKrellM

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_X_PREFIX=	yes
USE_GNOME=	imlib
USE_GMAKE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gkmouse.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
