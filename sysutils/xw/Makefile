# New ports collection makefile for:  xw
# Date created:                       26 January 20001
# Whom:                               Daniel Hemmerich <dan@BSDpro.com>
#
# $FreeBSD$
#

PORTNAME=	xw
PORTVERSION=	0.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mavetju.org/download/adopted/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X app to list current users logged into the system

GTK_CONFIG=${X11BASE}/bin/gtk12-config

USE_GNOME=	imlib
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

.include <bsd.port.post.mk>
