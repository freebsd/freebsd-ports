# New ports collection makefile for:	iiimf-csconv
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-csconv
PORTVERSION=	${IIIMF_VER:S/_/./:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/docs/im-sdk/
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}.${IIIMF_VER:S/-/./}${EXTRACT_SUFX}

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Framework encoding convert library

IIIMF_VER=	r11_4-1467
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/lib/CSConv
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,-pthread,g" \
		-e "s,-D_POSIX_C_SOURCE=199506L,,g" \
		-e "s,has_xiccallback=no,has_xiccallback=yes,g" \
		-e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		-e 's,x"gcc",x"cc",g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/csconv.h \
		${WRKSRC}/converterPI/test/icutest4linux.c \
		${WRKSRC}/converterPI/icuconv_relay.c \
		${WRKSRC}/converterPI/configure \
		${WRKSRC}/converterPI/icuconv/common/config.h
	${REINPLACE_CMD} -e "s,-lpthread,-pthread,g" -e "s,-ldl,," \
		${WRKSRC}/converterPI/icuconv/common/Makefile.in \
		${WRKSRC}/converterPI/icuconv/tools/toolutil/Makefile.in
	${REINPLACE_CMD} -e "s,ELIBBAD,-2," \
		${WRKSRC}/converterPI/icuconv/common/icuconv.c

.include <bsd.port.mk>
