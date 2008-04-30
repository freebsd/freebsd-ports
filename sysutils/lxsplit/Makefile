# New ports collection makefile for:   lxsplit
# Date created:        9 April 2003
# Whom:                kiesel@schlund.de
#
# $FreeBSD$
#

PORTNAME=	lxsplit
PORTVERSION=	0.2.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Simple program to split or join files

PLIST_FILES=	bin/lxsplit
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lxsplit ${PREFIX}/bin/

.include <bsd.port.mk>
