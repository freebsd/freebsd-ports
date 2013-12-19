# Created by: Kenjiro Cho <kjc@csl.sony.co.jp>
# $FreeBSD$

PORTNAME=	blt
PORTVERSION=	2.5.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/wize
DISTNAME=	${PORTNAME}-src-${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension to the Tk toolkit

LICENSE=	BSD

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}

USES=		gmake tk
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${TCL_INCLUDEDIR}/generic \
		-I${TK_INCLUDEDIR}/generic \
		-I${TK_INCLUDEDIR}/unix
MAKE_JOBS_UNSAFE=

PLIST_SUB+=	BLTVER=${PORTVERSION:R} \
    		BLTSHORTVER=${PORTVERSION:R:S/.//}

CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--exec_prefix=${PREFIX} \
		--enable-jpeg=${LOCALBASE} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-tcllibs=${LOCALBASE}/lib \
		--with-tklibs=${LOCALBASE}/lib

post-patch:
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
	    ${REINPLACE_CMD} -e '/^INSTALL_ROOT/s|$$|$${DESTDIR}|'
	${FIND} ${WRKSRC}/demos -name "*.tcl" | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|../src/bltwish|${LOCALBASE}/bin/bltwish|'

.include <bsd.port.pre.mk>

.if ${TCL_VER} > 8.5
CFLAGS+=	-DUSE_INTERP_RESULT -DUSE_INTERP_ERRORLINE
.endif

.include <bsd.port.post.mk>
