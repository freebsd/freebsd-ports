# New ports collection makefile for:	wmapmload
# Date created:				Sat Sep 21 01:48:10 EDT 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmapmload
PORTVERSION=	0.3.4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	APM battery status monitor dockapp with a similar look to wmcpuload

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/wmapmload
PLIST_DIRS=	share/nls/POSIX share/nls/en_US.US-ASCII

BINMODE=	2755
BINGRP=		operator

.include <bsd.port.mk>
