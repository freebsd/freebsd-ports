# New ports collection makefile for:   lxsplit
# Date created:        9 April 2003
# Whom:                kiesel@schlund.de
#
# $FreeBSD$
#

PORTNAME=	lxsplit
PORTVERSION=	0.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.freebyte.com/download/ \
		http://document-root.de/mirror/lxsplit/
DISTNAME=	lxsplit

MAINTAINER=	kiesel@schlund.de
COMMENT=	Simple program to split or join files

PLIST_FILES=	bin/lxsplit
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/lxsplit ${PREFIX}/bin/

post-install:
		${STRIP_CMD} ${PREFIX}/bin/lxsplit

.include <bsd.port.mk>
