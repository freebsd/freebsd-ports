# New ports collection makefile for:	jade
# Version required:	0.8
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $Id$
#

DISTNAME=	jade-0.8
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/

MAINTAINER=	jfieber@FreeBSD.ORG

DISTFILES=	jade0_8.zip
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-a -U -qq

NO_WRKSUBDIR=

# Unfortunately, jade needs a more modern C++ compiler than
# comes with FreeBSD 2.1.x.
.if !exists(/usr/lib/libstdc++.a)
BROKEN=		yes
.endif

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
