## New ports collection makefile for:   swt
# Date created:			28 March 2006
# Whom:				Max Brazhnikov makc@issp.ac.ru
#
# $FreeBSD$
#

PORTNAME=	swt
DISTVERSION=	0.1.0rc4
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scwt
PKGNAMEPREFIX=	scilab-toolbox-
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scilab 1-D and 2-D Wavelet Toolbox

BUILD_DEPENDS=	${LOCALBASE}/bin/scilab:${PORTSDIR}/math/scilab
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

SCILABDIR?=	lib/scilab
CONTRIBDIR?=	${SCILABDIR}/contrib
TOOLBOXDIR?=	${CONTRIBDIR}/${PORTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}/${TOOLBOXDIR}
CONFIGURE_ENV+=	SCI="${LOCALBASE}/${SCILABDIR}"

PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR}

OPTIONS=        SIVP "Enable Image and Video support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SIVP)
RUN_DEPENDS+=	${LOCALBASE}/${CONTRIBDIR}/sivp/loader.sce:${PORTSDIR}/math/scilab-toolbox-sivp
.endif

post-install:
	 @${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
