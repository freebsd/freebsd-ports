## New ports collection makefile for:   swt
# Date created:			28 March 2006
# Whom:				Max Brazhnikov makc@issp.ac.ru
#
# $FreeBSD$
#

PORTNAME=	swt
DISTVERSION=	0.1.0rc4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scwt
PKGNAMEPREFIX=	scilab-toolbox-
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Scilab 1-D and 2-D Wavelet Toolbox

BUILD_DEPENDS=	${LOCALBASE}/bin/scilab:${PORTSDIR}/math/scilab
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

SCI=		${LOCALBASE}/lib/scilab
TOOLBOXDIR?=	lib/scilab/contrib/swt

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}/${TOOLBOXDIR}
CONFIGURE_ENV+=	SCI="${SCI}"
USE_LDCONFIG=	${PREFIX}/${TOOLBOXDIR}

PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR}

post-install:
	 @${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
