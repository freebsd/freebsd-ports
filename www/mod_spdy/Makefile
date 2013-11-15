# Created by: Masaki TAGAWA
# $FreeBSD$

PORTNAME=	mod_spdy
PORTVERSION=	0.9.4.1
CATEGORIES=	www
MASTER_SITES=	http://www.club.kyutech.ac.jp/~masaki/ports/:mod_spdy \
		${MASTER_SITE_APACHE_HTTPD}:apache22
DISTFILES=	mod_spdy_source_${PORTVERSION}.tar.xz:mod_spdy \
		httpd-2.2.22.tar.gz:apache22
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	mod_spdy_source_${PORTVERSION}.tar.xz

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	SPDY module for the Apache HTTP server v2.2

LICENSE=	AL2

BUILD_DEPENDS=	greadlink:${PORTSDIR}/sysutils/coreutils \
		flock:${PORTSDIR}/sysutils/flock \
		svn:${PORTSDIR}/devel/subversion \
		curl:${PORTSDIR}/ftp/curl \
		bash:${PORTSDIR}/shells/bash

ONLY_FOR_ARCHS=	amd64 i386
USE_XZ=		yes
USE_OPENSSL=	yes
USE_APACHE=	22
USE_PYTHON=	2.6-2.7
USE_GMAKE=	yes
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
GCC_DESC=	Build mod_spdy with GCC 4.6+

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900033 || ${PORT_OPTIONS:MGCC}
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${PORT_OPTIONS:MGCC}
USE_GCC?=	yes
GYP_DEFINES+=	gcc_version=${CXX:S/g++//}
.else
.if ${OSVERSION} < 902000
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang32:${PORTSDIR}/lang/clang32
CC=		${LOCALBASE}/bin/clang32
CXX=		${LOCALBASE}/bin/clang++32
.else
CC=		clang
CXX=		clang++
.endif
GYP_DEFINES+=	clang=1
.endif

.if ${OSVERSION} < 1000052
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
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

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 && ${OSVERSION} < 901000
BROKEN=	does not link due to libtool not respecting CC
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
.if ${PORT_OPTIONS:MGCC}
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
	cd ${WRKSRC} && CONFIGURE_ENV='${CONFIGURE_ENV}' BUILDROOT=${WRKSRC}/temp \
		${WRKSRC}/build_modssl_with_npn.sh

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
