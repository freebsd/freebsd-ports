# New ports collection makefile for:	jade
# Version required:	1.0
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.6 1997/07/23 00:50:50 jfieber Exp $
#

DISTNAME=	jade1_0
PKGNAME=	jade-1.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/
EXTRACT_SUFX=	.zip

MAINTAINER=	jfieber@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-a -U -qq
NO_WRKSUBDIR=	yes

# Unfortunately, jade needs a more modern C++ compiler than
# comes with FreeBSD 2.1.x.
.if !exists(/usr/lib/libstdc++.a)
BROKEN=		Requires FreeBSD 2.2 or later.
.endif

# Shared libraries are currently broken for this port.
# post-install:
# 	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
