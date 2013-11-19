# Created by: Kenjiro Cho <kjc@csl.sony.co.jp>
# $FreeBSD$

PORTNAME=	blt
PORTVERSION=	2.5.3
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/wize
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension to the Tk toolkit

LICENSE=	BSD

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}

USES+=		gmake tk:84,85
USE_ZIP=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${TCL_INCLUDEDIR}/generic
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

.include <bsd.port.mk>
