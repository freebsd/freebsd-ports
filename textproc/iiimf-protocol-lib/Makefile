# New ports collection makefile for:	iiimf-protocol-lib
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-protocol-lib
PORTVERSION=	${IIIMF_VER:S/_/./:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/docs/im-sdk/
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}.${IIIMF_VER:S/-/./}${EXTRACT_SUFX}

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Framework protocol library

IIIMF_VER=	r11_4-1467
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/lib/iiimp
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}-${IIIMF_VER}
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--includedir=${PREFIX}/include/iiimf/iiimp

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,-pthread,g" \
		-e "s,-D_POSIX_C_SOURCE=199506L,,g" \
		-e "s,has_xiccallback=no,has_xiccallback=yes,g" \
		-e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
