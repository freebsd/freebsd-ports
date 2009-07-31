# New ports collection makefile for:	gkrellmouse
# Date Created:				Fri Aug 17 15:57:42 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellmouse
PORTVERSION=	0.0.2
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nafpik.com/paul/gkrellmouse/ \
		http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mouse odometer plugin for GKrellM

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

PLIST_FILES=	libexec/gkrellm/plugins/gkmouse.so
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_GNOME=	imlib
USE_GMAKE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gkmouse.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
