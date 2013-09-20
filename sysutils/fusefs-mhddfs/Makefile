# Created by: Oleg Alexeenkov <proler@gmail.com>
# $FreeBSD$

PORTNAME=	mhddfs
PORTVERSION=	0.1.37
CATEGORIES=	sysutils
MASTER_SITES=	http://mhddfs.uvw.ru/downloads/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	proler@gmail.com
COMMENT=	Multi HDD [FUSE] File System

USES=		fuse pkgconfig
USE_GMAKE=	yes
MAKE_ARGS=	WITHOUT_XATTR=1
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README ChangeLog

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
