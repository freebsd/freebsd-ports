# New ports collection makefile for:	mod_pagespeed
# Date created:		2011-09-27
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_pagespeed
PORTVERSION=	20110927
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
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_XZ=		yes
USE_BINUTILS=	yes
USE_APACHE=	22+
USE_PYTHON=	2.6+
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
MAKE_ENV+=	BUILDTYPE=Release
WRKSRC=		${WRKDIR}/${PORTNAME}_source_${PORTVERSION}/mod_pagespeed/src
GYP_DEFINES+=	\
		use_system_apache_dev=1 \
		use_system_libjpeg=1 \
		use_system_libpng=1 \
		use_system_zlib=1 \
		system_include_path_httpd=${LOCALBASE}/include/apache22 \
		system_include_path_apr=${LOCALBASE}/include/apr-1 \
		system_include_path_aprutil=${LOCALBASE}/include/apr-1 \
		system_include_path_execinfo=${LOCALBASE}/include \
		include_dirs=${LOCALBASE}/include

.include <bsd.port.pre.mk>

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
