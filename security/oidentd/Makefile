# New ports collection makefile for:	oidentd
# Version required:	1.6.4
# Date created:		29 Mar 2000
# Whom:			trevor@jpj.net
#
# $FreeBSD$
#

DISTNAME=	oidentd-1.6.4
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/ojnk/ \
		http://www.numb.org/~odin/stuff/

MAINTAINER=	trevor@jpj.net

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN8=		oidentd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
BROKEN=		"outdated sys/file.h"
.endif

.include <bsd.port.post.mk>
