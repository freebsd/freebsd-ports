# New ports collection Makefile for:	matrixssl
# Date created:				2006-03-17
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	matrixssl
PORTVERSION=	1.7.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.,-,g}-open

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Small alternative SSL implementation

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/matrixssl/src
INSTALLS_SHLIB=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmatrixssl* ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/../*.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/../doc/* ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/../examples/* ${EXAMPLESDIR}
	cd ${EXAMPLESDIR}; ${RM} *.vcproj *.sln *.orig
.endif

.include <bsd.port.mk>
