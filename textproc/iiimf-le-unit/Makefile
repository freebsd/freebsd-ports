# New ports collection makefile for:	iiimf-le-unit
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-le-unit
PORTVERSION=	${IIIMF_VER:S/_/./:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/docs/im-sdk/
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}.${IIIMF_VER:S/-/./}${EXTRACT_SUFX}

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Framework language engine unit

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

IIIMF_VER=	r11_4-1467
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/leif
BUILD_WRKSRC=	${WRKSRC}/unit
INSTALL_WRKSRC=	${WRKSRC}/unit
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,-pthread,g" \
		-e "s,-D_POSIX_C_SOURCE=199506L,,g" \
		-e "s,has_xiccallback=no,has_xiccallback=yes,g" \
		-e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/unit/include/indic_input.h

.include <bsd.port.mk>
