# Created by: Masaki TAGAWA
# $FreeBSD$

PORTNAME=	mod_spdy
PORTVERSION=	0.9.3.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.club.kyutech.ac.jp/~masaki/ports/:mod_spdy \
		${MASTER_SITE_APACHE_HTTPD}:apache22 \
		http://www.openssl.org/source/:openssl
DISTFILES=	mod_spdy_source_${PORTVERSION}.tar.xz:mod_spdy \
		httpd-2.2.22.tar.gz:apache22 \
		openssl-1.0.1c.tar.gz:openssl
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	mod_spdy_source_${PORTVERSION}.tar.xz

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	A SPDY module for the Apache HTTP server v2.2

BUILD_DEPENDS=	greadlink:${PORTSDIR}/sysutils/coreutils \
		flock:${PORTSDIR}/sysutils/flock \
		svn:${PORTSDIR}/devel/subversion \
		curl:${PORTSDIR}/ftp/curl \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_XZ=		yes
USE_APACHE=	22
USE_PYTHON=	2.6+
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	amd64 i386
REINPLACE_ARGS=	-i ""
LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}_source_${PORTVERSION}/mod_spdy/src
GYP_DEFINES+=	\
		use_system_apache_dev=1 \
		use_system_zlib=1 \
		system_include_path_httpd=${LOCALBASE}/include/apache22 \
		system_include_path_apr=${LOCALBASE}/include/apr-1 \
		system_include_path_aprutil=${LOCALBASE}/include/apr-1 \
		system_include_path_execinfo=${LOCALBASE}/include \
		include_dirs=${LOCALBASE}/include

OPTIONS_DEFINE=	CLANG DEBUG
CLANG_DESC=	Build with Clang instead of GCC 4.6+
DEBUG_DESC=	Compile with debug symbols and verbose output

OPTIONS_DEFAULT=	CLANG

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${OSVERSION} < 900033 || ! ${PORT_OPTIONS:MCLANG}
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${PORT_OPTIONS:MCLANG}
.if ${OSVERSION} < 900033 || !exists(/usr/bin/clang)
BUILD_DEPENDS+=	clang33:${PORTSDIR}/lang/clang33
CC=	clang33
CXX=	clang++33
.else
CC=	clang
CXX=	clang++
.endif
GYP_DEFINES+=	clang=1
.else
USE_GCC?=	yes
GYP_DEFINES+=	gcc_version=${CXX:S/g++//}
.endif

.if ${PORT_OPTIONS:MDEBUG}
BUILDTYPE=	Release
.else
MAKE_ENV+=	V=1
BUILDTYPE=	Debug
.endif

MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
CFLAGS+=	-Wno-error

SUB_FILES+=	mod_spdy.conf
SUB_LIST+=	APACHEMODDIR=${APACHEMODDIR}

.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/temp/progress
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/httpd-2.2.22.tar.gz ${WRKSRC}/temp/ && \
		${TOUCH} ${WRKSRC}/temp/progress/httpd-2.2.22.tar.gz.downloaded
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/openssl-1.0.1c.tar.gz ${WRKSRC}/temp/ && \
		${TOUCH} ${WRKSRC}/temp/progress/openssl-1.0.1c.tar.gz.downloaded

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/base/base.gypi
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${WRKSRC}/build_modssl_with_npn.sh

do-configure:
	@cd ${WRKSRC} && \
		GYP_DEFINES="${GYP_DEFINES}" ${PYTHON_CMD} \
			../../depot_tools/gclient.py runhooks

pre-build:
	@cd ${WRKSRC} && \
		BUILDROOT=${WRKSRC}/temp ${WRKSRC}/build_modssl_with_npn.sh

do-install:
	@${INSTALL} ${WRKSRC}/out/${BUILDTYPE}/libmod_spdy.so ${PREFIX}/${APACHEMODDIR}/mod_spdy.so
	@${INSTALL} ${WRKSRC}/mod_ssl.so ${PREFIX}/${APACHEMODDIR}/mod_ssl_with_npn.so
	@${INSTALL_DATA} ${WRKDIR}/mod_spdy.conf ${PREFIX}/${APACHEETCDIR}/Includes

post-install:
	@${REINPLACE_CMD} -e 's/mod_ssl.so/mod_ssl_with_npn.so/g' ${PREFIX}/${APACHEETCDIR}/httpd.conf

.include <bsd.port.post.mk>
