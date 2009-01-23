# New ports collection makefile for:   XawPlus
# Date created:        30 January 2003
# Whom:                DNPM <freebsd@falx.port5.com>
#
# $FreeBSD$
#

PORTNAME=	XawPlus
PORTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://people.freenet.de/kra/XawPlus/
DISTNAME=	${PORTNAME:L}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A replacement for Xaw with a nicer 3-D look and some extensions

USE_XORG=	x11 xaw
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CC="${CC}" FLAGS="${CFLAGS} -fPIC -DHAS_WCHAR_H" \
		INC_PATH="-I. -I${LOCALBASE}/include" LIB_PATH="-L${LOCALBASE}/lib"
ALL_TARGET=	lib
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's:so\.3\..:so.3:' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:%%LOCALBASE%%:${LOCALBASE}:' ${WRKSRC}/test/Makefile

do-install:
	@${MKDIR} ${PREFIX}/include/X11/XawPlus
	${INSTALL_DATA} ${WRKSRC}/X11/XawPlus/*.h ${PREFIX}/include/X11/XawPlus
	${INSTALL_DATA} ${WRKSRC}/libXawPlus.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libXawPlus.so.3 ${PREFIX}/lib
	${LN} -sf libXawPlus.so.3 ${PREFIX}/lib/libXawPlus.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/Makefile ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/*.xpm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
