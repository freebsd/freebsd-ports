# Created by: Masaki TAGAWA
# $FreeBSD$

PORTNAME=	mod_spdy
PORTVERSION=	0.9.4.1
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.club.kyutech.ac.jp/~masaki/ports/:mod_spdy \
		APACHE_HTTPD:apache22
DISTFILES=	mod_spdy_source_${PORTVERSION}.tar.xz:mod_spdy \
		httpd-2.2.22.tar.gz:apache22
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	mod_spdy_source_${PORTVERSION}.tar.xz

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	SPDY module for the Apache HTTP server v2.2

LICENSE=	APACHE20

BUILD_DEPENDS=	python:lang/python \
		greadlink:sysutils/coreutils \
		flock:sysutils/flock \
		svn:devel/subversion \
		curl:ftp/curl \
		bash:shells/bash

ONLY_FOR_ARCHS=	amd64 i386
USE_APACHE=	22
USES=		compiler execinfo gmake python:2 ssl tar:xz
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}_source_${PORTVERSION}/mod_spdy/src
CFLAGS+=	-fno-stack-protector -Wno-unknown-warning-option -Wno-c++11-extensions -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
GYP_DEFINES+=	\
		use_system_apache_dev=1 \
		use_system_zlib=1 \
		system_include_path_httpd=${LOCALBASE}/include/apache22 \
		system_include_path_apr=${LOCALBASE}/include/apr-1 \
		system_include_path_aprutil=${LOCALBASE}/include/apr-1 \
		system_include_path_execinfo=${LOCALBASE}/include \
		include_dirs=${LOCALBASE}/include

SUB_FILES+=	mod_spdy.conf
SUB_LIST+=	APACHEMODDIR=${APACHEMODDIR}

OPTIONS_DEFINE=	GCC DEBUG

# workaround for archs with no clang in base, part 1:
# do not include the option to turn GCC off.  Instead, force its use.
OPTIONS_EXCLUDE_sparc64=	GCC

.include <bsd.port.options.mk>

# workaround for archs with no clang in base, part 2
.if ${PORT_OPTIONS:MGCC} || ${ARCH} == sparc64
FORCE_GCC=	yes
.else
FORCE_GCC=	no
.endif

.if ${FORCE_GCC} == yes
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${FORCE_GCC} == yes
USE_GCC?=	yes
GYP_DEFINES+=	gcc_version=${CXX:S/g++//}
.else
CC=		clang
CXX=		clang++
GYP_DEFINES+=	clang=1
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ENV+=	V=1
BUILDTYPE=	Debug
.else
BUILDTYPE=	Release
GYP_DEFINES+=	buildtype=Official
.endif

CONFIGURE_ENV+=	CC=${CC} \
		CXX=${CXX} \
		GYP_DEFINES="${GYP_DEFINES}"
# according to portlint the below is passed via bsd.port.mk,
# but 'make -V CONFIGURE_ENV' does not show it:
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}"
MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}

BROKEN_SSL=		libressl libressl-devel
BROKEN_SSL_REASON=	please use www/apache24 with mod_http2

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 36
CXXFLAGS+=	-Wno-unused-local-typedef
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/temp/progress
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/httpd-2.2.22.tar.gz ${WRKSRC}/temp/ && \
		${TOUCH} ${WRKSRC}/temp/progress/httpd-2.2.22.tar.gz.downloaded

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/base/base.gypi
	@${REINPLACE_CMD} -e 's,#!/bin/bash,#!${LOCALBASE}/bin/bash,' \
		-e 's,%%FILESDIR%%,${FILESDIR},g' \
			-e 's,%%OPENSSLBASE%%,${OPENSSLBASE},g' \
			${WRKSRC}/build_modssl_with_npn.sh
.if ${FORCE_GCC} == yes
	@${REINPLACE_CMD} -e 's,%%GCCCXXFLAGS%%,-I${LOCALBASE}/lib/gcc${CXX:S/g++//}/include,g' \
		-e 's,%%GCCLDFLAGS%%,-L${LOCALBASE}/lib/gcc${CXX:S/g++//},g' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,%%GCCCXXFLAGS%%,-I${LOCALBASE}/lib/gcc${CXX:S/g++//}/include,g' \
		-e 's,%%GCCLDFLAGS%%,-L${LOCALBASE}/lib/gcc${CXX:S/g++//},g' \
			${WRKSRC}/tools/gyp/pylib/gyp/generator/make.py
.else
	@${REINPLACE_CMD} -e 's,%%GCCCXXFLAGS%%,,g' \
		-e 's,%%GCCLDFLAGS%%,,g' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,%%GCCCXXFLAGS%%,,g' \
		-e 's,%%GCCLDFLAGS%%,,g' \
			${WRKSRC}/tools/gyp/pylib/gyp/generator/make.py
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		../../depot_tools/gclient.py runhooks

pre-build:
	cd ${WRKSRC} && CONFIGURE_ENV='${CONFIGURE_ENV}' \
		BUILDROOT=${WRKSRC}/temp ${WRKSRC}/build_modssl_with_npn.sh

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${APACHEMODDIR} \
		${STAGEDIR}/${PREFIX}/${APACHEETCDIR}/Includes
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libmod_spdy.so \
		${STAGEDIR}/${PREFIX}/${APACHEMODDIR}/mod_spdy.so
	${INSTALL_LIB} ${WRKSRC}/mod_ssl.so \
		${STAGEDIR}/${PREFIX}/${APACHEMODDIR}/mod_ssl_with_npn.so
	${INSTALL_DATA} ${WRKDIR}/mod_spdy.conf \
		${STAGEDIR}/${PREFIX}/${APACHEETCDIR}/Includes/mod_spdy.conf

.include <bsd.port.post.mk>
