# New ports collection makefile for:	iiimf-client-lib
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-client-lib
PORTVERSION=	${IIIMF_VER:S/_/./:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/docs/im-sdk/
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}.${IIIMF_VER:S/-/./}${EXTRACT_SUFX}

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Client Framework

LIB_DEPENDS=	iiimp.0:${PORTSDIR}/textproc/iiimf-protocol-lib

IIIMF_VER=	r11_4-1467
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}
INSTALL_WRKSRC=	${WRKSRC}/lib/iiimcf
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--includedir=${PREFIX}/include/iiimf
DIRS=		lib/EIMIL lib/iiimcf

post-patch:
.for DIR in ${DIRS}
	${REINPLACE_CMD} -e "s,-lpthread,-pthread,g" \
		-e "s,-D_POSIX_C_SOURCE=199506L,,g" \
		-e "s,has_xiccallback=no,has_xiccallback=yes,g" \
		-e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		-e "s,-I\$$(IM_INCLUDEDIR),-I${LOCALBASE}/include/iiimf,g" \
		${WRKSRC}/${DIR}/configure
.endfor

do-configure:
.for DIR in ${DIRS}
	cd ${WRKSRC}/${DIR} && ${SH} configure ${CONFIGURE_ARGS}
.endfor

do-build:
.for DIR in ${DIRS}
	cd ${WRKSRC}/${DIR} && ${GMAKE} all
.endfor

.include <bsd.port.mk>
