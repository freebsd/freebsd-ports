# New ports collection makefile for:	jade
# Version required:	1.2
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.11 1998/06/05 16:47:12 jfieber Exp $
#

DISTNAME=	jade1_2
PKGNAME=	jade-1.2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/
EXTRACT_SUFX=	.zip

MAINTAINER=	jfieber@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-a -U -qq
NO_WRKSUBDIR=	yes

# Shared libraries are currently broken for this port.
# post-install:
# 	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
