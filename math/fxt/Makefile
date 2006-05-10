# ex:ts=8
# New ports collection makefile for:	fxt
# Date created:			Nov 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fxt
PORTVERSION=	2006.04.12
CATEGORIES=	math
MASTER_SITES=	http://www.jjj.de/fxt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FFT code and related stuff

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GCC=	3.4+
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ENV=	CXX="${CXX}" OFLAGS="${CXXFLAGS}"

PLIST_FILES=	lib/libfxt.a

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^OFLAGS|#OFLAGS|g ; \
		 s|^ARCHFLAG|#ARCHFLAG|g ; \
		 s|^WFLAGS|#WFLAGS|g ; \
		 s|^GFLAGS|#GFLAGS|g ; \
		 s|^PFLAGS|#PFLAGS|g ; \
		 s|^FXT_CXXFLAGS|#FXT_CXXFLAGS|g' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|sinl|Sin|g' ${WRKSRC}/src/aux0/trigrec.h
	@${REINPLACE_CMD} -e 's|sinl|sin|g' ${WRKSRC}/src/fht/hartleyshift.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/libfxt.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/fxt
	cd ${WRKSRC}/src && ${FIND} . -name "*.h" | \
		${CPIO} -pdm -L -R ${SHAROWN}:${SHAREGRP} ${PREFIX}/include/fxt
	@${FIND} ${PREFIX}/include/fxt -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${PREFIX}/include/fxt -type d | ${XARGS} ${CHMOD} ${BINMODE}
	@${FIND} ${PREFIX}/include/fxt ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/fxt -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/00*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
