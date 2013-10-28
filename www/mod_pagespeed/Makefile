# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_pagespeed
PORTVERSION=	1.2.24.2
PORTREVISION=	0
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

USES=		gmake pkgconfig
USE_XZ=		yes
USE_BINUTILS=	yes
USE_APACHE=	22
USE_PYTHON=	2.6+

# debugging
#MAKE_ENV+=     V=1

# seems new version isn't JOBS safe
MAKE_JOBS_UNSAFE=      yes

ONLY_FOR_ARCHS=	amd64 i386
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
MAKE_ENV+=	BUILDTYPE=Release
ALL_TARGET=	mod_pagespeed_test pagespeed_automatic_test all html_minifier_main css_minify_main
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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# testing
#USE_GCC=	yes
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
	${INSTALL_PROGRAM} out/Release/css_minify_main ${PREFIX}/bin ; \
	${INSTALL_PROGRAM} out/Release/html_minifier_main ${PREFIX}/bin ; \
	${INSTALL_PROGRAM} out/Release/js_minify ${PREFIX}/bin ; \
	${INSTALL} out/Release/libmod_pagespeed.so ${PREFIX}/${APACHEMODDIR}/mod_pagespeed.so
	if [ ! -f ${PREFIX}/${APACHEETCDIR}/pagespeed.conf-dist ] ; then \
		cd ${WRKSRC}/install && \
		${CAT} common/pagespeed.load.template common/pagespeed.conf.template | \
			${SED} -e "s,@@COMMENT_OUT_DEFLATE@@,," \
				-e "s,@@APACHE_MODULEDIR@@,${APACHEMODDIR}," \
				-e "s,@@MOD_PAGESPEED_STATS_LOG@@,/var/log/mod_pagespeed_stats.log," \
				-e "s,@@MOD_PAGESPEED_CACHE@@,/var/mod_pagespeed/,g" \
				> ${PREFIX}/${APACHEETCDIR}/pagespeed.conf-dist ; \
	fi
	if [ ! -f ${PREFIX}/${APACHEETCDIR}/pagespeed_libraries.conf-dist ] ; then \
		${INSTALL_DATA} ${WRKSRC}/net/instaweb/genfiles/conf/pagespeed_libraries.conf ${PREFIX}/${APACHEETCDIR}/pagespeed_libraries.conf-dist ; \
	fi

post-install:
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} -m 755 /var/mod_pagespeed
	@if [ ! -f ${PREFIX}/etc/pagespeed.conf ]; then \
		${CP} -p ${PREFIX}/${APACHEETCDIR}/pagespeed.conf-dist ${PREFIX}/${APACHEETCDIR}/pagespeed.conf ; \
	fi
	@if [ ! -f ${PREFIX}/etc/pagespeed_libraries.conf ]; then \
		${CP} -p ${PREFIX}/${APACHEETCDIR}/pagespeed_libraries.conf-dist ${PREFIX}/${APACHEETCDIR}/pagespeed_libraries.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
