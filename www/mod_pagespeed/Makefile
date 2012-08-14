# New ports collection makefile for:	mod_pagespeed
# Date created:		2011-09-27
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_pagespeed
PORTVERSION=	0.10.22.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	swills
DISTNAME=	mod_pagespeed_source_${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	An Apache module that automatically optimizes web pages

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		greadlink:${PORTSDIR}/sysutils/coreutils \
		gsed:${PORTSDIR}/textproc/gsed \
		svn:${PORTSDIR}/devel/subversion \
		flock:${PORTSDIR}/sysutils/flock
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		icutu:${PORTSDIR}/devel/icu \
		opencv_legacy:${PORTSDIR}/graphics/opencv \
		execinfo:${PORTSDIR}/devel/libexecinfo

USE_XZ=		yes
USE_BINUTILS=	yes
USE_APACHE=	22+
USE_PYTHON=	2.6+
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

# debugging
#MAKE_ENV+=     V=1
#MAKE_JOBS_UNSAFE=      yes

ONLY_FOR_ARCHS=	amd64 i386
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
MAKE_ENV+=	BUILDTYPE=Release
WRKSRC=		${WRKDIR}/${PORTNAME}_source_${PORTVERSION}/mod_pagespeed/src
GYP_DEFINES+=	\
		use_system_apache_dev=1 \
		use_system_libjpeg=1 \
		use_system_libpng=1 \
		use_system_zlib=1 \
		use_system_icu=1 \
		use_system_opencv=1 \
		target_arch=${ARCH} \
		system_include_path_apr=${LOCALBASE}/include/apr-1 \
		system_include_path_aprutil=${LOCALBASE}/include/apr-1 \
		system_include_path_httpd=${LOCALBASE}/include/apache22 \
		system_include_path_execinfo=${LOCALBASE}/include \
		system_include_path_icu=${LOCALBASE}/include \
		include_dirs=${LOCALBASE}/include

.include <bsd.port.pre.mk>

# testing
#USE_GCC=	4.6+
#.if ${OSVERSION} > 1000000
#CC=		clang
#CXX=		clang++
#GYP_DEFINES+=	clang=1
#.endif

.if ${OSVERSION} < 802517 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900502)
EXTRA_PATCHES=		${FILESDIR}/extra-gperf.gypi
BUILD_DEPENDS+=		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf
.endif

post-patch:
	( cd ${BUILD_WRKSRC}/third_party/gflags/gen/arch && ${CP} -R linux freebsd && \
		cd ${BUILD_WRKSRC}/third_party/gflags/gen/arch/freebsd && ${MV} ia32 i386 && ${MV} x64 amd64 )
	( cd ${BUILD_WRKSRC}/third_party/google-sparsehash/gen/arch && ${CP} -R linux freebsd && \
		cd ${BUILD_WRKSRC}/third_party/google-sparsehash/gen/arch/freebsd && ${MV} ia32 i386 && ${MV} x64 amd64 )
	( cd ${BUILD_WRKSRC}/third_party/opencv/gen/arch && ${CP} -R linux freebsd && \
		cd ${BUILD_WRKSRC}/third_party/opencv/gen/arch/freebsd && ${MV} ia32 i386 && ${MV} x64 amd64 )
	${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/base/base.gypi
	${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%CC%%,${CC},g" \
		-e "s,%%CXX%%,${CXX},g" \
		${WRKSRC}/tools/gyp/pylib/gyp/generator/make.py
.if ${OSVERSION} < 802517 || ${OSVERSION} < 900502
	${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/net/instaweb/gperf.gypi
.endif

do-configure:
	cd ${WRKSRC} && \
		GYP_DEFINES="${GYP_DEFINES}" ${PYTHON_CMD} \
			../../depot_tools/gclient.py runhooks

do-install:
	cd ${WRKSRC} && \
	${INSTALL} out/Release/libmod_pagespeed.so ${PREFIX}/${APACHEMODDIR}/mod_pagespeed.so
	if [ ! -f ${PREFIX}/${APACHEETCDIR}/pagespeed.conf-dist ] ; then \
		cd ${WRKSRC}/install && \
		${CAT} common/pagespeed.load.template common/pagespeed.conf.template | \
			${SED} -e "s,@@COMMENT_OUT_DEFLATE@@,," \
				-e "s,@@APACHE_MODULEDIR@@,${APACHEMODDIR}," \
				-e "s,@@MODPAGESPEED_CACHE_ROOT@@,/var/mod_pagespeed/,g" \
				> ${PREFIX}/${APACHEETCDIR}/pagespeed.conf-dist ; \
	fi

post-install:
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} -m 755 /var/mod_pagespeed/cache
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} -m 755 /var/mod_pagespeed/files
	@if [ ! -f ${PREFIX}/etc/pagespeed.conf ]; then \
		${CP} -p ${PREFIX}/${APACHEETCDIR}/pagespeed.conf-dist ${PREFIX}/${APACHEETCDIR}/pagespeed.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
