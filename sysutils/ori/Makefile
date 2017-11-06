# Created by: Ali Mashtizadeh <mashti@cs.stanford.edu>
# $FreeBSD$

PORTNAME=	ori
PORTVERSION=	0.8.1
PORTREVISION=	12
CATEGORIES=	sysutils net
MASTER_SITES=	http://cdn.bitbucket.org/orifs/ori/downloads/

PATCH_SITES=	https://bitbucket.org/orifs/ori/commits/
PATCHFILES=	48862f2477b1/raw:-p1

MAINTAINER=	mashti@cs.stanford.edu
COMMENT=	Ori distributed file system

LIB_DEPENDS=	libevent.so:devel/libevent \
		libboost_date_time.so:devel/boost-libs

USES=		compiler:c++11-lib fuse pkgconfig scons ssl tar:xz
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto
MAKE_ARGS=	VERBOSE=1

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
