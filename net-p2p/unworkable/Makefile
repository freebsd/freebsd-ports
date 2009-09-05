# New ports collection makefile for:	unworkable
# Date created:				06 Oct 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	unworkable
PORTVERSION=	0.52
CATEGORIES=	net-p2p
MASTER_SITES=	http://p2presearch.com/unworkable/dist/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Free BitTorrent Implementation

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent

USE_SCONS=	yes
USE_OPENSSL=	yes
SCONS_BUILDENV=	${SCONS_ENV}
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/unworkable

MAN1=	unworkable.1

post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unworkable ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unworkable.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
