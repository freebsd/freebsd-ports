# New ports collection makefile for:	harvest
# Date created:		Fri Mar  1 19:43:52 MET 1996
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	harvest
PORTVERSION=	1.9.10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Collect information from all over the Internet

USE_BZIP2=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--prefix=${PREFIX}/${PORTNAME} \
		--without-wish

STRIP=		# none

MAN1=		curl-config.1 curl.1 yaz-client-ssl.1 yaz-client.1 \
		yaz-config.1 zebraidx.1 zoomsh.1
MAN3=		curl_easy_cleanup.3 curl_easy_duphandle.3 curl_easy_getinfo.3 \
		curl_easy_init.3 curl_easy_perform.3 curl_easy_setopt.3 \
		curl_escape.3 curl_formadd.3 curl_formfree.3 curl_formparse.3 \
		curl_free.3 curl_getdate.3 curl_getenv.3 curl_global_cleanup.3 \
		curl_global_init.3 curl_mprintf.3 curl_multi_add_handle.3 \
		curl_multi_cleanup.3 curl_multi_fdset.3 curl_multi_info_read.3 \
		curl_multi_init.3 curl_multi_perform.3 \
		curl_multi_remove_handle.3 curl_slist_append.3 \
		curl_slist_free_all.3 curl_strequal.3 curl_strnequal.3 \
		curl_unescape.3 curl_version.3 curl_version_info.3 \
		libcurl-errors.3 libcurl-multi.3 libcurl.3
MAN7=		yaz.7
MAN8=		yaz-ztest-ssl.8 yaz-ztest.8 zebrasrv.8
MANPREFIX=	${PREFIX}/harvest

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "<malloc.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'

post-configure:
.if ${OSVERSION} > 501101
	@${ECHO_MSG} "#define __STRICT_ANSI__ 1" >> ${WRKSRC}/src/common/include/autoconf.h
	@${REINPLACE_CMD} "s!DEFS\(.*\)!DEFS\1 -D__STRICT_ANSI__!" \
			${WRKSRC}/components/gatherer/standard/pstext/libs/src/sio/Makefile
	@${REINPLACE_CMD} "s!DEFS\(.*\)=\(.*\)!DEFS\1 = -D__STRICT_ANSI__ \2 !" \
			${WRKSRC}/components/gatherer/standard/pstext/libs/src/str/Makefile
	@${REINPLACE_CMD} "s!DEFS\(.*\)!DEFS\1 -D__STRICT_ANSI__!" \
			${WRKSRC}/components/gatherer/standard/pstext/pstext/Makefile
.endif
	@${REINPLACE_CMD} "s!^INSTALL =\(.*\)!INSTALL = ${INSTALL}!" \
			${WRKSRC}/src/gatherer/curl/lib/Makefile

post-install:
	@(cd ${PREFIX} && ${GREP} -v "@" ${PLIST} | \
		${XARGS} ${STRIP_CMD} 2> /dev/null || ${TRUE})

.include <bsd.port.post.mk>
