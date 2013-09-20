# Created by: Michael Ebert <ebert@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	relview
PORTVERSION=	7.0.2
PORTREVISION=	2
CATEGORIES=	math linux
MASTER_SITES=	ftp://ftp.informatik.uni-kiel.de/pub/kiel/relview/RELVIEW_7.0/LINUX/
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive tool for manipulation of relations

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	gtk xorglibs

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${DISTNAME}

NO_BUILD=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

NO_STAGE=	yes
do-install:
	${BRANDELF} -t Linux ${WRKDIR}/${DISTNAME}
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin
	${LN} -fhs ${PREFIX}/bin/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
