# New ports collection makefile for:	nvu
# Date created:		August 21, 2004
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	nvu
PORTVERSION=	0.50
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete Web Authoring System

BUILD_DEPENDS=	${X11BASE}/lib/mozilla/libmozjs.so:${PORTSDIR}/www/mozilla
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/mozilla

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKEFILE=	client.mk
ALL_TARGET=	build_all

PLIST_SUB=	NVUDIR=${PORTNAME}-0.17+

post-extract:
	${CP} -p ${WRKSRC}/mozconfig.linux ${WRKSRC}/.mozconfig

.include <bsd.port.mk>
