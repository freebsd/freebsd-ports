# New ports collection makefile for:	hawknl
# Date created:		2006-03-04
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	hawknl
PORTVERSION=	1.70
CATEGORIES=	net devel
MASTER_SITES=	http://www.hawksoft.com/download/files/
PKGNAMESUFFIX=	-devel
DISTNAME=	HawkNL17b1src
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Portable networking library (devel)

CONFLICTS=	hawknl-[0-9]*

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile.linux
USE_LDCONFIG=	yes

LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS=	-I${LOCALBASE}/include
MAKE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"

WRKSRC=	${WRKDIR}/HawkNL1.70

OPTIONS=	OPTIMIZATION	"Enable optimization"	off

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == ia64
BROKEN=		does not compile on ${ARCH}
.endif

.if defined(WITH_OPTIMIZATION)
CFLAGS+=	-funroll-all-loops -ffast-math -fomit-frame-pointer -D_GNU_SOURCE -D_REENTRANT
.endif

post-patch:
	${REINPLACE_CMD} -e 's|make -f|${GMAKE} -f|g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/nlinternal.h ${WRKSRC}/src/htinternal.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in readme.txt NLchanges.txt
	@${INSTALL_DATA} ${WRKSRC}/src/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
