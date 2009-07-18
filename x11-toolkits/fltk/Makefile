# New ports collection makefile for:   	fltk
# Date created:				11 February 1999
# Whom:                			Dima Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION=	1.1.9
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=	fltk/${PORTVERSION}
.ifdef WITH_THREADS
PKGNAMESUFFIX=	-threads
.endif
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Cross-platform C++ graphical user interface toolkit

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=--enable-threads
CPPFLAGS+=	"${PTHREAD_CFLAGS}"
LDFLAGS+=	"${PTHREAD_LIBS}"
CONFLICTS=	fltk-1*
.else
CONFLICTS=	fltk-threads-1*
.endif

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_XORG=	xft
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --enable-xft
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# configure ignores ${CXX} and keeps on linking C++ code with ${CC}
CONFIGURE_ENV+=	CC="${CXX}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GL=		gl glu

MAN1=		fluid.1 fltk-config.1
MAN3=		fltk.3

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_THREADS)
	@${ECHO_MSG} "===>  You can enable threads support by defining WITH_THREADS"
	@${ECHO_MSG} "===>"
.endif

post-patch:
	${REINPLACE_CMD} -e 's|.$${FL_MINOR_VERSION}||; \
	    s|CAT1EXT=0|CAT1EXT=1|g; s|CAT3EXT=0|CAT3EXT=3|g' \
	    ${WRKSRC}/configure ${WRKSRC}/configure.in
	${REINPLACE_CMD} -e 's|.1.1|.1|g' ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -e 's|LINKSHARED)|LINKSHARED) ../src/fl_gtk.o|' \
	    ${WRKSRC}/fluid/Makefile
	${REINPLACE_CMD} -e 's|cat1|man1|g;s|cat3|man3|g' ${WRKSRC}/documentation/Makefile
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|test ||' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '234,238d' ${WRKSRC}/documentation/Makefile
.endif

.include <bsd.port.post.mk>
