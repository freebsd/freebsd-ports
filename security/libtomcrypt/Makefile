# Ports collection makefile for:  libtomcrypt
# Date created:			  22 Jan 2004
# Whom:				  Yonatan <Yonatan@Xpert.com>
#
# $FreeBSD$
#

PORTNAME=	libtomcrypt
PORTVERSION=	1.00
CATEGORIES=	security
MASTER_SITES=	http://libtomcrypt.org/files/
DISTNAME=	crypt-${PORTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Comprehensive, modular and portable cryptographic toolkit

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV=	PREFIX=${PREFIX} DOCSDIR=${DOCSDIR} EXAMPLESDIR=${EXAMPLESDIR}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	library

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript-gnu
.else
NOPORTDOCS=	yes
INSTALL_TARGET=	install_lib
.endif

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${WRKSRC}/demos/test && ${MAKE} test ${MAKE_ARGS} && ${WRKSRC}/demos/test/test)
.endif

.include <bsd.port.mk>
