# New ports collection makefile for:  xw
# Date created:                       26 January 20001
# Whom:                               Daniel Hemmerich <dan@spot.org>
#
# $FreeBSD$
#

PORTNAME=	xw
PORTVERSION=	0.1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.gurubox.com/pub/xw/ \
		ftp://ftp.databits.net/pub/xw/

MAINTAINER=	dan@spot.org

BUILD_DEPENDS=	imlib:${PORTSDIR}/graphics/imlib

GTK_CONFIG=${X11BASE}/bin/gtk12-config

USE_GTK=  yes
USE_X_PREFIX=  yes

.include <bsd.port.mk>
