# New ports collection makefile for:	iiimf-headers
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	headers
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	Header files for Internet/Intranet Input Method Framework

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/include/iiimf
.for file in IMArg.h IMCharSubsets.h IMProtocolStruct.h syscfg.h threaddef.h
	${INSTALL_DATA} ${WRKSRC}/include/${file} ${PREFIX}/include/iiimf
.endfor
	${MKDIR} ${PREFIX}/include/iiimf/iml
	${INSTALL_DATA} ${WRKSRC}/include/iml/*.h ${PREFIX}/include/iiimf/iml

.include <bsd.port.mk>
