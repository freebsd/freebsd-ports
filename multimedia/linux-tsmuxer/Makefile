# New ports collection makefile for:	tsMuxeR (Linux version)
# Date created:				2010-01-02
# Whom:					Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	tsmuxer
PORTVERSION=	1.10.6
CATEGORIES=	multimedia linux
MASTER_SITES=	http://www.smlabs.net/tsMuxer/
PKGNAMEPREFIX=	linux-
DISTNAME=	tsMuxeR_${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Utility to create TS and M2TS files for IP broadcasting

USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/tsMuxeR bin/tsMuxerGUI

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/tsMuxeR ${WRKDIR}/tsMuxerGUI \
		${PREFIX}/bin

.include <bsd.port.mk>
