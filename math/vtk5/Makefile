# New ports collection makefile for:    vtk
# Date created:         24 Nov 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vtk
PORTVERSION=	3.2
CATEGORIES=	math
MASTER_SITES=	ftp://public.kitware.com/pub/vtk/vtk${PORTVERSION}/
DISTNAME=	vtk32-src-unix
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_MESA=	yes
WRKSRC=		${WRKDIR}/vtk${PORTVERSION}
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mesa --with-shared --with-tcl --with-bsdmake
CONFIGURE_ARGS+=	--with-contrib --with-tkwidget

# Support for Python is compiled in by default.
.if !defined(WITHOUT_PYTHON)
CONFIGURE_ARGS+=	--with-python
USE_PYTHON=	yes
.endif

.if defined(WITH_PATENTED)
CONFIGURE_ARGS+=	--with-patented
PLIST=		${PKGDIR}/pkg-plist.with_patented
.endif

post-patch:
	${PERL} -pi -e "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g; \
		s|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g" \
		${WRKSRC}/user.make
	@${FIND} ${WRKSRC} -name "*.cxx" | ${XARGS} ${PERL} -pi -e \
		's|malloc.h|stdlib.h|'

post-install:
.if !defined(WITHOUT_PYTHON)
	${PYTHON_CMD}  -c "import compileall; compileall.compile_dir( '${PREFIX}/lib/vtk/python' );"
	${PYTHON_CMD} -Oc "import compileall; compileall.compile_dir( '${PREFIX}/lib/vtk/python' );"
.endif

.include <bsd.port.mk>
