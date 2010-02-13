# New ports collection makefile for:	tsMuxeR
# Date created:		2010-01-02
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	tsMuxeR
PORTVERSION=	1.10.6
CATEGORIES=	multimedia linux x11
MASTER_SITES=	http://www.smlabs.net/tsMuxer/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	steve@mouf.net
COMMENT=	Utility to create TS and M2TS files

WRKSRC=		${WRKDIR}
USE_LINUX=	yes
PLIST_FILES=	bin/tsMuxerGUI bin/tsMuxeR

do-build:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tsMuxerGUI ${PREFIX}/bin/tsMuxerGUI
	${INSTALL_SCRIPT} ${WRKDIR}/tsMuxeR ${PREFIX}/bin/tsMuxeR

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
