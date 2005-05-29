# New ports collection makefile for:	xdiskusage
# Date created:				2000-09-23
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	xdiskusage
PORTVERSION=	1.48
CATEGORIES=	x11-fm
MASTER_SITES=	http://xdiskusage.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Show where disk space is taken up

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

MAN1=		xdiskusage.1
USE_GMAKE=	yes
USE_X_PREFIX=	yes
OPTIONS=	THREADS	"Threads support, necessary with threaded fltk" off

.include <bsd.port.pre.mk>

.if defined(WITH_THREADS)
CXXFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.endif

do-build:
.for i in panels xdiskusage
	${CXX} ${CXXFLAGS} -I${X11BASE}/include -c \
		${WRKSRC}/${i}.C -o ${WRKSRC}/${i}.o
.endfor
	${CXX} ${CXXFLAGS} -L${X11BASE}/lib -o \
		${WRKSRC}/xdiskusage ${WRKSRC}/panels.o \
		${WRKSRC}/xdiskusage.o -lfltk -lm -lXext -lX11 ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdiskusage ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdiskusage.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
