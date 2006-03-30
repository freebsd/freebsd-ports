# New ports collection makefile for:	hawknl
# Date created:		2006-03-04
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	hawknl
PORTVERSION=	1.68
CATEGORIES=	net devel
MASTER_SITES=	http://www.hawksoft.com/download/files/
DISTNAME=	HawkNL168src
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Portable networking library

USE_DOS2UNIX=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile.linux
INSTALLS_SHLIB=	yes

LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS} ${OPTFLAGS}" \
		LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"

WRKSRC=	${WRKDIR}/${PORTNAME}${PORTVERSION}

OPTIONS=	OPTIMIZATION	"Enable optimization"	off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

.if ${OSVERSION} < 500000
BROKEN=	Doesn't build on < 5.x
.endif

.if defined(WITH_OPTIMIZATION)
CFLAGS+=	-funroll-all-loops -ffast-math -fomit-frame-pointer -D_GNU_SOURCE -D_REENTRANT
.endif

post-patch:
	${REINPLACE_CMD} -e 's|make -f|${GMAKE} -f|g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/nlinternal.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in readme.txt nlchanges.txt
	${INSTALL_DATA} ${WRKSRC}/src/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
