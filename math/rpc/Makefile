# ex:ts=8
# New ports collection makefile for:	rpc
# Date created:			Mar 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rpc
PORTVERSION=	0.98
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/rpc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-screen RPN calculator program

BUILD_DEPENDS=	${LOCALBASE}/lib/libccm.so:${PORTSDIR}/math/ccmath
RUN_DEPENDS=	${LOCALBASE}/lib/libccm.so:${PORTSDIR}/math/ccmath

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
#
# Get rid of inline function body in implementation...
#
	@${REINPLACE_CMD} -e '483,488d' ${WRKSRC}/src/RpcComplex.cpp
	@${REINPLACE_CMD} -e '428,433d' ${WRKSRC}/src/RpcComplexMatrix.cpp
	@${REINPLACE_CMD} -e '591,596d' ${WRKSRC}/src/RpcDouble.cpp
	@${REINPLACE_CMD} -e '350,355d' ${WRKSRC}/src/RpcIntegerConst.cpp
	@${REINPLACE_CMD} -e '394,399d' ${WRKSRC}/src/RpcRealMatrix.cpp
#
# ...and put it right into class declaration instead, to please newer GCC
#
	@${REINPLACE_CMD} -E 's,([[:alnum:]]+ getData\( void \));,inline \1 { return data; },' \
		${WRKSRC}/src/RpcComplex.h ${WRKSRC}/src/RpcComplexMatrix.h \
		${WRKSRC}/src/RpcDouble.h ${WRKSRC}/src/RpcIntegerConst.h \
		${WRKSRC}/src/RpcRealMatrix.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual ${DOCSDIR}
.endif

.include <bsd.port.mk>
