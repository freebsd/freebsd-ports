# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	unworkable
PORTVERSION=	0.53
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Free BitTorrent Implementation

LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent

USE_SCONS=	yes
USE_OPENSSL=	yes

SCONS_BUILDENV=	${SCONS_ENV}
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/unworkable man/man1/unworkable.1.gz

post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unworkable ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unworkable.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
