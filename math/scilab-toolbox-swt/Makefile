## New ports collection makefile for:   swt
# Date created:			28 March 2006
# Whom:				Max Brazhnikov makc@issp.ac.ru
#
# $FreeBSD$
#

PORTNAME=	swt
PORTVERSION=	0.1.0.r3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scwt
PKGNAMEPREFIX=	scilab-toolbox-
DISTNAME=	${PORTNAME}-0.1.0rc3

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Scilab 1-D and 2-D Wavelet Toolbox

BUILD_DEPENDS=	scilab:${PORTSDIR}/math/scilab

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib/scilab/contrib/swt/lib

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}/lib/scilab/contrib/swt
TOOLBOXDIR=	lib/scilab/contrib/swt
PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR}

post-install@:
	@${ECHO_MSG} "==========================================================="
	@${ECHO_MSG} "NOTE: SWT should be recompiled whenever Scilab is upgraded."
	@${ECHO_MSG} "==========================================================="

.include <bsd.port.mk>
