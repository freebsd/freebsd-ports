# Ports collection makefile for:	pear-Net_Portscan
# Date created:				21 Dec, 2009
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net_Portscan
PORTVERSION=	1.0.3
CATEGORIES=	security pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Provides an API for scanning ports

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Portscan.php
TESTS=		01-portscan.php
DOCS=		README.portscan

post-extract:
	@cd ${WRKSRC} && ${MKDIR} -p ${WRKSRC}/docs
	${MV} ${WRKSRC}/README.portscan ${WRKSRC}/docs/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
