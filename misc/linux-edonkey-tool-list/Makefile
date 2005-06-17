# New ports collection makefile for:	edonkey list tool
# Date created:				Wed Feb 20 18:03:49 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	misc linux
MASTER_SITES=	http://users.aber.ac.uk/tpm01/ed2k_tools/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-tool-list
DISTNAME=	ed2k_list
EXTRACT_SUFX=	.gz
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates a web page with ed2k:// links to all your shared files

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/edonkey-tool-list

BINARY_NAME=	${PORTNAME}${PKGNAMESUFFIX}

post-extract:
	@${GZCAT} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKSRC}/${BINARY_NAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin

.include <bsd.port.pre.mk>

pre-install:
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME}
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME}

.include <bsd.port.post.mk>
