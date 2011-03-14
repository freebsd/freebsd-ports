# New ports collection makefile for:	edonkey recovermet tool
# Date created:				Wed Feb 20 18:03:49 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	net-p2p linux
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-tool-recovermet
DISTNAME=	ed2k_recovermet-0.2_alpha

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that tries to re-create x.part.met files compromised due to crash

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/edonkey-tool-recovermet

BINARY_NAME=	ed2k_recovermet

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME} \
		${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

pre-install:
.if exists(${STRIP_CMD})
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME}
.endif
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
