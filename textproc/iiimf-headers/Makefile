# New ports collection makefile for:	iiimf-headers
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	headers
PORTVERSION=	12.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	Header files for Internet/Intranet Input Method Framework

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
USE_BZIP2=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/include/iiim
.for file in IMArg.h IMCharSubsets.h IMProtocolStruct.h syscfg.h threaddef.h
	${INSTALL_DATA} ${WRKSRC}/include/${file} ${PREFIX}/include/iiim
.endfor
	${MKDIR} ${PREFIX}/include/iiim/iml
	${INSTALL_DATA} ${WRKSRC}/include/iml/*.h ${PREFIX}/include/iiim/iml

.include <bsd.port.mk>
