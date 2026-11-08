PORTNAME=	vss-text
DISTVERSION=	26.2
CATEGORIES=	textproc devel lang

MAINTAINER=	ada@FreeBSD.org
COMMENT=	Ada library for Unicode text processing
WWW=		https://github.com/AdaCore/vss-text

LICENSE=	APACHE20
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild

USES=		ada:14,run
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
USE_LDCONFIG=	yes

MAKE_CMD=	gprbuild

NO_SHLIB_REQUIRES_GLOB=	libgnarl-${_ada_version}.so libgnat-${_ada_version}.so

PLIST_SUB=	SO_VERSION=${_SO_VERSION}

_GPRBUILD_ARGS=		${_GPR_PROJECT_ARGS} -j${MAKE_JOBS_NUMBER} -p -vh -vP2
_GPRINSTALL_ARGS=	${_GPR_PROJECT_ARGS} --no-manifest \
			--prefix='${STAGEDIR}${PREFIX}' -p -v
_GPR_LIBRARY_TYPES=	relocatable static static-pic
_GPR_PROJECT_ARGS=	-XVSS_BUILD_PROFILE=${WITH_DEBUG:Urelease:Ddevelopment}
_SO_VERSION=		${DISTVERSION:R}
_VSS_PROJECTS=		vss_gnat vss_text

pre-configure:
	${REINPLACE_CMD} -e 's|%%SO_VERSION%%|${_SO_VERSION}|' \
		${WRKSRC}/gnat/${PORTNAME:C/-/_/}.gpr \
		${WRKSRC}/gnat/${PORTNAME:C/-.*/_gnat/}.gpr

do-build:
. for _project in ${_VSS_PROJECTS}
.  for _library_type in ${_GPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/gnat/ && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -XVSS_LIBRARY_TYPE=${_library_type} \
		-P ${_project})
.  endfor
. endfor

do-install:
. for _project in ${_VSS_PROJECTS}
.  for _library_type in ${_GPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/gnat && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --ali-subdir=libdata/${PORTNAME}/${_project:C|vss_||}/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/${PORTNAME}/${_project:C|vss_||}/${_library_type} \
		--sources-subdir=include/${PORTNAME}/${_project:C|vss_||}/ \
		-XVSS_LIBRARY_TYPE=${_library_type} -P ${_project})
.  endfor
. endfor
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.a -exec ${STRIP_CMD} {} \
		\;
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.so* -exec ${STRIP_CMD} \
		{} \;

.include <bsd.port.mk>
