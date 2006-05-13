# New ports collection makefile for:   XawPlus
# Date created:        30 January 2003
# Whom:                DNPM <freebsd@falx.port5.com>
#
# $FreeBSD$
#

PORTNAME=	XawPlus
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://people.freenet.de/kra/XawPlus/
DISTNAME=	${PORTNAME:L}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A replacement for Xaw with a nicer 3-D look and some extensions

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CC}" FLAGS="${CFLAGS} -fPIC -DHAS_WCHAR_H" \
		INC_PATH="-I. -I${X11BASE}/include" LIB_PATH="-L${X11BASE}/lib"
ALL_TARGET=	lib
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's:so\.3\..:so.3:' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:%%X11BASE%%:${X11BASE}:' ${WRKSRC}/test/Makefile

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
