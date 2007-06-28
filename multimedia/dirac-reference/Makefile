# New ports collection makefile for:	dirac-reference
# Date created:		2006-09-24
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-reference

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Programming reference for dirac

BUILD_DEPENDS+=		dot:${PORTSDIR}/graphics/graphviz \
			doxygen:${PORTSDIR}/devel/doxygen

MASTERDIR=	${.CURDIR}/../../multimedia/dirac

BROKEN=		Incorrect pkg-plist
BUILD_WRKSRC=	${WRKSRC}/doc
INSTALL_WRKSRC=	${WRKSRC}/doc
PLIST=	${.CURDIR}/pkg-plist
CONFIGURE_ENV=	# empty

.include "${MASTERDIR}/Makefile"
