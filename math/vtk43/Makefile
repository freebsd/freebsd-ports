# New ports collection makefile for:    vtk
# Version required:     3.1
# Date created:         24 Nov 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	vtk31Unix
PKGNAME=	vtk-3.1
CATEGORIES=	math
MASTER_SITES=	ftp://public.kitware.com/pub/vtk/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=
LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3	\
		tk82.1:${PORTSDIR}/x11-toolkits/tk82
RUN_DEPENDS=

WRKSRC=		$(WRKDIR)/vtk31
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-mesa --with-shared --with-tcl --with-bsdmake
CONFIGURE_ARGS+=	--with-contrib --with-tkwidget
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CXXFLAGS="${CFLAGS}"

# Support for Python is compiled in by default.
WITH_PYTHON?=	yes
.if defined(WITH_PYTHON) && $(WITH_PYTHON) == yes
CONFIGURE_ARGS+=	--with-python
BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
RUN_DEPENDS+=	python:${PORTSDIR}/lang/python
.endif

WITH_PATENTED?=	no
.if defined(WITH_PATENTED) && $(WITH_PATENTED) == yes
CONFIGURE_ARGS+=	--with-patented
PLIST=		${PKGDIR}/PLIST.with_patented
.endif

post-install:
.if defined(WITH_PYTHON) && $(WITH_PYTHON) == yes
	${PREFIX}/bin/python  -c "import compileall; compileall.compile_dir( '${PREFIX}/lib/vtk/python' );"
	${PREFIX}/bin/python -Oc "import compileall; compileall.compile_dir( '${PREFIX}/lib/vtk/python' );"
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
