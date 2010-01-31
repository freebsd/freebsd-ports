# New ports collection Makefile for:	matrixssl
# Date created:				2006-03-17
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	matrixssl
PORTVERSION=	1.8.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small alternative SSL implementation

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/matrixssl-1-8-8-open/src
USE_LDCONFIG=	yes

post-extract:
	cd ${WRKDIR} && ${TAR} -xvf matrixssl-1-8-8-open.tgz

post-patch:
	${REINPLACE_CMD} -e "s,^CC,#CC,;s,-O3,${CFLAGS}," ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmatrixssl* ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/../*.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/../doc/* ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/../examples/* ${EXAMPLESDIR}
	-cd ${EXAMPLESDIR}; ${RM} *.vcproj *.sln *.orig
.endif

.include <bsd.port.mk>
