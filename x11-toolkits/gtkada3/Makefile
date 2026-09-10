PORTNAME=	gtkada
DISTVERSIONPREFIX=	v
DISTVERSION=	26.2
CATEGORIES=	x11-toolkits devel
PKGNAMESUFFIX=	3

MAINTAINER=	ada@FreeBSD.org
COMMENT=	Ada bindings for the GTK+ graphical widget library
WWW=		https://docs.adacore.com/live/wave/gtkada/html/gtkada_ug/index.html

LICENSE=	GPLv3+ GPLv3RLE+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING3
LICENSE_FILE_GPLv3RLE+ =	${WRKSRC}/COPYING.RUNTIME

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild

USES=		ada:run gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_TAGNAME=	0e438bed1b1fbf15a6a69334c1f41a42c0af0b32
USE_GNOME=	cairo glib20 gtk30
USE_LDCONFIG=	yes

MAKE_CMD=	gprbuild

NO_SHLIB_REQUIRES_GLOB=	libgnat-${_ada_version}.so

EXTRACT_AFTER_ARGS=	${_DIST_EXCLUDES:S,^,--exclude ,}

PLIST_SUB=	SO_RELEASE=${_SO_RELEASE} \
		SO_VERSION=${_SO_VERSION}

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext

# docs requires gnatdoc
_DIST_EXCLUDES=		.cvs* .git* aclocal.m4 config* docs doinstall features* \
			install-sh known-problems* m4 Makefile*
_GPRBUILD_ARGS=		${_GPR_PROJECT_ARGS} -j${MAKE_JOBS_NUMBER} -p -vh -vP2
_GPRINSTALL_ARGS=	${_GPR_PROJECT_ARGS} --no-manifest \
			--prefix='${STAGEDIR}${PREFIX}' -p -v
_GPR_LIBRARY_TYPES=	relocatable static static-pic
_GPR_PROJECT_ARGS=	-XBUILD_TYPE=${WITH_DEBUG:UProduction:DDebug} \
			-XGTK_PREFIX=${LOCALBASE}
_SO_RELEASE=		${DISTVERSION:R}
_SO_VERSION=		${DISTVERSION}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/pkgconf)
_GTK_CFLAGS!=	(pkgconf --cflags gtk+-3.0)
_GTK_LIBS!=	(pkgconf --libs gtk+-3.0)
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|@BUILD_TYPE@|${WITH_DEBUG:UProduction:DDebug}|' \
		-e 's|@DEFAULT_LIBRARY_TYPE@|relocatable|' \
		-e 's|@GTK_CFLAGS_GPR@|"${_GTK_CFLAGS}"|' \
		-e 's|@GTK_LIBS_GPR@|"${_GTK_LIBS}"|' \
		-e 's|@NEED_OBJECTIVE_C@|no|' \
		-e 's|@PACKAGE_VERSION@|${DISTVERSION}|' \
		-e 's|@SO_EXT@|.so|' \
		${WRKSRC}/${PORTNAME}_shared.gpr.in
	${MV} ${WRKSRC}/${PORTNAME}_shared.gpr.in \
		${WRKSRC}/${PORTNAME}_shared.gpr

pre-build-NLS-on:
	(cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} gnatprep -DGETTEXT_INTL=True -DHAVE_GETTEXT=True \
		gtkada-intl.gpb gtkada-intl.adb)

pre-build-NLS-off:
	(cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} gnatprep -DGETTEXT_INTL=False -DHAVE_GETTEXT=False \
		gtkada-intl.gpb gtkada-intl.adb)

do-build:
.  for _library_type in ${_GPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -XLIBRARY_TYPE=${_library_type} \
		-P ${PORTNAME})
.  endfor

do-install:
.  for _library_type in ${_GPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --ali-subdir=libdata/${PORTNAME}/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/${PORTNAME}/${_library_type} --sources-subdir=include/${PORTNAME} \
		-XLIBRARY_TYPE=${_library_type} -P ${PORTNAME})
.  endfor

.include <bsd.port.post.mk>
