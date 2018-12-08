# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	tsmuxer
PORTVERSION=	1.10.6
CATEGORIES=	multimedia linux
MASTER_SITES=	http://twocats.free.fr/pub/h264tobox/
PKGNAMEPREFIX=	linux-
DISTNAME=	tsMuxeR_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to create TS and M2TS files for IP broadcasting

USES=		linux
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/tsMuxeR bin/tsMuxerGUI
STRIP=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tsMuxeR ${WRKSRC}/tsMuxerGUI \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
