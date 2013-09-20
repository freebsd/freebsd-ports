# Created by: Ali Mashtizadeh <mashti@cs.stanford.edu>
# $FreeBSD$

PORTNAME=	ori
PORTVERSION=	0.7.0
CATEGORIES=	sysutils net
MASTER_SITES=	http://cdn.bitbucket.org/orifs/ori/downloads/

MAINTAINER=	mashti@cs.stanford.edu
COMMENT=	Ori Distributed File System

LIB_DEPENDS+=	event-2:${PORTSDIR}/devel/libevent2 \
		boost_date_time:${PORTSDIR}/devel/boost-libs \
		execinfo:${PORTSDIR}/devel/libexecinfo

USE_XZ=	yes
WRKSRC=	${WRKDIR}

USES=	pkgconfig fuse
USE_SCONS=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes

PLIST_FILES=	bin/ori \
		bin/orifs \
		bin/ori_httpd
MAN1=		ori.1 orifs.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${ECHO_MSG} "===>  Installing binaries..."
	${INSTALL_PROGRAM} ${WRKSRC}/build/ori/ori ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/orifs/orifs ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/ori_httpd/ori_httpd ${PREFIX}/bin/
	@${ECHO_MSG} "===>  Installing man pages..."
	${INSTALL_MAN} ${WRKSRC}/docs/ori.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/orifs.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
