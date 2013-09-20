# Created by: Matthew Dillon <dillon@backplane.com>
# $FreeBSD$

PORTNAME=	cpdup
PORTVERSION=	1.17
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://apollo.backplane.com/FreeSrc/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gmarco@gufi.org
COMMENT=	A comprehensive filesystem mirroring and backup program

WRKSRC=		${WRKDIR}/${PORTNAME}

CFLAGS+=	-D_ST_FLAGS_PRESENT_

MAN1=		cpdup.1
PLIST_FILES=	bin/cpdup

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpdup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpdup.1 ${PREFIX}/man/man1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
