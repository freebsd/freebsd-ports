# New ports collection makefile for:	wmupmon
# Date created:				Thu Jul  3 14:49:14 EDT 2003
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmupmon
PORTVERSION=	0.1.2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://j-z-s.com/projects/downloads/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	An uptime showing dockapp with a similar look to wmcpuload

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		wmupmon.1
PLIST_FILES=	bin/wmupmon

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

.include <bsd.port.post.mk>
