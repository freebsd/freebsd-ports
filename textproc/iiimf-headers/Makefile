# New ports collection makefile for:	iiimf-headers
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-headers
PORTVERSION=	${IIIMF_VER:S/_/./:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/docs/im-sdk/
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}.${IIIMF_VER:S/-/./}${EXTRACT_SUFX}

MAINTAINER=	kcwu@csie.org
COMMENT=	Header files for Internet/Intranet Input Method Framework

IIIMF_VER=	r11_4-1467
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}
USE_BZIP2=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/include/iiimf
.for file in IMArg.h IMProtocolStruct.h syscfg.h threaddef.h
	${INSTALL_DATA} ${WRKSRC}/include/${file} ${PREFIX}/include/iiimf
.endfor
	${MKDIR} ${PREFIX}/include/iiimf/iml
	${INSTALL_DATA} ${WRKSRC}/include/iml/*.h ${PREFIX}/include/iiimf/iml

.include <bsd.port.mk>
