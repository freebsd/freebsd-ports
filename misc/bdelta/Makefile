# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bdelta
PORTVERSION=	0.1.0
CATEGORIES=	misc devel
MASTER_SITES=	SF/deltup/${PORTNAME}/${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	An advanced delta creator, patcher, and library

USE_GMAKE=	yes
USE_LDCONFIG=	yes
PLIST_FILES=	bin/bdelta \
		bin/bpatch \
		lib/libbdelta.so

MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bdelta ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bpatch ${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/libbdelta.so ${PREFIX}/lib

.include <bsd.port.mk>
