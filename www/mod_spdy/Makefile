# New ports collection makefile for:	mod_spdy
# Date created:        1 April 2012
# Whom:                Masaki TAGAWA
#
# $FreeBSD$
#

PORTNAME=	mod_spdy
PORTVERSION=	0.9.1.5
CATEGORIES=	www
MASTER_SITES=	http://www.club.kyutech.ac.jp/~masaki/ports/:mod_spdy \
		${MASTER_SITE_APACHE_HTTPD}:apache22 \
		http://www.openssl.org/source/:openssl
DISTFILES=	mod_spdy_source_${PORTVERSION}.tar.xz:mod_spdy \
		httpd-2.2.22.tar.gz:apache22 \
		openssl-1.0.1.tar.gz:openssl
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
USE_BINUTILS=	yes
USE_APACHE=	22+
USE_PYTHON=	2.6+
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
ONLY_FOR_ARCHS=	amd64 i386
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	BUILDTYPE=Release
WRKSRC=		${WRKDIR}/${PORTNAME}_source_${PORTVERSION}/mod_spdy/src
GYP_DEFINES+=	\
		use_system_apache_dev=1 \
		use_system_zlib=1 \
		system_include_path_httpd=${LOCALBASE}/include/apache22 \
		system_include_path_apr=${LOCALBASE}/include/apr-1 \
		system_include_path_aprutil=${LOCALBASE}/include/apr-1 \
		system_include_path_execinfo=${LOCALBASE}/include \
		include_dirs=${LOCALBASE}/include
SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} \
		APACHEMODDIR=${PREFIX}/${APACHEMODDIR}

.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/temp/progress
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/httpd-2.2.22.tar.gz ${WRKSRC}/temp/ && \
		${TOUCH} ${WRKSRC}/temp/progress/httpd-2.2.22.tar.gz.downloaded
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/openssl-1.0.1.tar.gz ${WRKSRC}/temp/ && \
		${TOUCH} ${WRKSRC}/temp/progress/openssl-1.0.1.tar.gz.downloaded

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/base/base.gypi
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${WRKSRC}/build_modssl_with_npn.sh

pre-build:
	@cd ${WRKSRC} && \
		BUILDROOT=${WRKSRC}/temp ${WRKSRC}/build_modssl_with_npn.sh

do-configure:
	@cd ${WRKSRC} && \
		GYP_DEFINES="${GYP_DEFINES}" ${PYTHON_CMD} \
			../../depot_tools/gclient.py runhooks

do-install:
	@cd ${WRKSRC} && \
		${INSTALL} out/Release/libmod_spdy.so ${PREFIX}/${APACHEMODDIR}/mod_spdy.so
	@${MKDIR} ${DATADIR}
	@${INSTALL} ${WRKSRC}/mod_ssl.so ${DATADIR}/mod_ssl.so

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
