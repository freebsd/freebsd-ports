# New ports collection makefile for:	iiimf-csconv
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	csconv
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Framework encoding convert library

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/lib/CSConv
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}-${IIIMF_VER}
USE_ICONV=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=259
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../../acfiles/im_common.m4 \
		${WRKSRC}/configure.ac \
		${WRKSRC}/aclocal.m4 \
		${WRKSRC}/csconv.h \
		${WRKSRC}/converterPI/test/icutest4linux.c \
		${WRKSRC}/converterPI/icuconv_relay.c \
		${WRKSRC}/converterPI/configure.in \
		${WRKSRC}/converterPI/icuconv/common/config.h
	${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" -e "s,-ldl,," -e 's,-lc$$,,' \
		${WRKSRC}/converterPI/icuconv/common/Makefile.in \
		${WRKSRC}/converterPI/icuconv/tools/toolutil/Makefile.in \
		${WRKSRC}/converter/compoundtext/Makefile.in
	${REINPLACE_CMD} -e "s,ELIBBAD,-2," \
		${WRKSRC}/converterPI/icuconv/common/icuconv.c
	${REINPLACE_CMD} -e "s,(LIBS),(LIBS) ${PTHREAD_LIBS},g" \
		${WRKSRC}/converterPI/icuconv/tools/makeconv/Makefile.in \
		${WRKSRC}/converterPI/icuconv/tools/gencnval/Makefile.in

.include <bsd.port.mk>
