# New ports collection makefile for:    vtk
# Date created:         24 Nov 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vtk
PORTVERSION=	3.1.2
CATEGORIES=	math
MASTER_SITES=	ftp://public.kitware.com/pub/vtk/
DISTNAME=	vtk312Unix

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3	\
		tk82.1:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/vtk31
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mesa --with-shared --with-tcl --with-bsdmake
CONFIGURE_ARGS+=	--with-contrib --with-tkwidget

# Support for Python is compiled in by default.
.if !defined(WITHOUT_PYTHON)
CONFIGURE_ARGS+=	--with-python
BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
RUN_DEPENDS+=	python:${PORTSDIR}/lang/python
.endif

.if defined(WITH_PATENTED)
CONFIGURE_ARGS+=	--with-patented
PLIST=		${PKGDIR}/PLIST.with_patented
.endif

post-install:
.if !defined(WITHOUT_PYTHON)
	${PREFIX}/bin/python  -c "import compileall; compileall.compile_dir( '${PREFIX}/lib/vtk/python' );"
	${PREFIX}/bin/python -Oc "import compileall; compileall.compile_dir( '${PREFIX}/lib/vtk/python' );"
.endif

.include <bsd.port.mk>
