# Ports collection makefile for:	rubygem-httparty
# Date created:				Nov 07, 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$

PORTNAME=	httparty
PORTVERSION=	0.4.3
CATEGORIES=	www rubygems
MASTER_SITES=	RF

MAINTAINER=	wenheping@gmail.com
COMMENT=	Ruby Library that Makes HTTP Fun Again

BUILD_DEPENDS=	rubygem-crack>=0.1.1:${PORTSDIR}/devel/rubygem-crack
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/httparty

.include <bsd.port.mk>
