# Ports collection makefile for:	simlib
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
# Date created:				26 Nov 2004
#
# $FreeBSD$
#

PORTNAME=	simlib
PORTVERSION=	3.0.20081216
CATEGORIES=	science
MASTER_SITES=	http://www.fit.vutbr.cz/~peringer/SIMLIB/source/
DISTNAME=	${PORTNAME}-3-${PORTVERSION:E}

MAINTAINER=	wenheping@gmail.com
COMMENT=	SIMulation LIBrary for C++ programming language

USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-3

CXXFLAGS+=	-fPIC

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON=	contains not working ${ARCH}-dependent assembly code

post-patch:
	@${REINPLACE_CMD} -e 's|make|gmake|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
		${WRKSRC}/src/Makefile.generic
	@${MV} ${WRKSRC}/src/Makefile.FreeBSD-i386 ${WRKSRC}/src/Makefile
	@${MV} ${WRKSRC}/examples/Makefile.FreeBSD-i386 ${WRKSRC}/examples/Makefile
	@${MV} ${WRKSRC}/tests/Makefile.FreeBSD-i386 ${WRKSRC}/tests/Makefile

.include <bsd.port.mk>
