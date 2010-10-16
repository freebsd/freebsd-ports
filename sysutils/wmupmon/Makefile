# New ports collection makefile for:	wmupmon
# Date created:				Thu Jul  3 14:49:14 EDT 2003
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmupmon
PORTVERSION=	0.1.3
PORTREVISION=	4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://j-z-s.com/projects/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An uptime showing dockapp with a similar look to wmcpuload

USE_BZIP2=	yes
USE_XORG=	xpm
USE_AUTOTOOLS=	autoheader:268
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		wmupmon.1
PLIST_FILES=	bin/wmupmon

.include <bsd.port.mk>
