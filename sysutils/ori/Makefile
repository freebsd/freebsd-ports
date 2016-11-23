# Created by: Ali Mashtizadeh <mashti@cs.stanford.edu>
# $FreeBSD$

PORTNAME=	ori
PORTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	sysutils net
MASTER_SITES=	http://cdn.bitbucket.org/orifs/ori/downloads/

MAINTAINER=	mashti@cs.stanford.edu
COMMENT=	Ori distributed file system

LIB_DEPENDS=	libevent.so:devel/libevent2 \
		libboost_date_time.so:devel/boost-libs

USES=		execinfo fuse pkgconfig scons tar:xz
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes

PLIST_FILES=	bin/ori \
		bin/oridbg \
		bin/orifs \
		bin/orisync \
		man/man1/ori.1.gz \
		man/man1/oridbg.1.gz \
		man/man1/orifs.1.gz \
		man/man1/orisync.1.gz

do-install:
	@${ECHO_MSG} "===>  Installing binaries..."
	${INSTALL_PROGRAM} ${WRKSRC}/build/ori/ori ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/oridbg/oridbg ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/orifs/orifs ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/orisync/orisync ${STAGEDIR}${PREFIX}/bin/
	@${ECHO_MSG} "===>  Installing man pages..."
	${INSTALL_MAN} ${WRKSRC}/docs/ori.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/oridbg.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/orifs.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/orisync.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
