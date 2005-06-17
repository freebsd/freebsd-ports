# New ports collection makefile for:	edonkey recovermet tool
# Date created:				Wed Feb 20 18:03:49 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	misc linux
MASTER_SITES=	http://users.aber.ac.uk/tpm01/ed2k_tools/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-tool-recovermet
DISTNAME=	ed2k_recovermet
EXTRACT_SUFX=	.gz
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that tries to re-create x.part.met files compromised due to crash

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/edonkey-tool-recovermet

BINARY_NAME=	${PORTNAME}${PKGNAMESUFFIX}

post-extract:
	@${GZCAT} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKSRC}/${BINARY_NAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin

.include <bsd.port.pre.mk>

pre-install:
.if exists(${STRIP_CMD})
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME}
.endif
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
