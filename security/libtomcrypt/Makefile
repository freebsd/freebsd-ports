# Ports collection makefile for:  libtomcrypt
# Date created:			  22 Jan 2004
# Whom:				  Yonatan <Yonatan@Xpert.com>
#
# $FreeBSD$
#

PORTNAME=	libtomcrypt
PORTVERSION=	0.98
CATEGORIES=	security
MASTER_SITES=	http://libtomcrypt.org/files/
DISTNAME=	crypt-${PORTVERSION}

MAINTAINER=	Yonatan@xpert.com
COMMENT=	Comprehensive, modular and portable cryptographic toolkit

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
MAKE_ENV=	PREFIX=${PREFIX} DOCSDIR=${DOCSDIR} EXAMPLESDIR=${EXAMPLESDIR}
USE_BZIP2=	yes
USE_REINPLACE=	yes
ALL_TARGET=	library

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
.else
NOPORTDOCS=	yes
INSTALL_TARGET=	install-nodocs
.endif

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${WRKSRC} && ${MAKE} test && ${WRKSRC}/test)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|||' ${WRKSRC}/whirl.c

.include <bsd.port.mk>
