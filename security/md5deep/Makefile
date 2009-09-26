# New ports collection makefile for:	md5deep
# Date created:		15 July 2004
# Whom:			Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	md5deep
PORTVERSION=	3.4
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Program to compute various message digests recursively

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		md5deep.1 hashdeep.1
MLINKS=		md5deep.1 sha1deep.1 md5deep.1 sha256deep.1 \
		md5deep.1 whirlpooldeep.1 md5deep.1 tigerdeep.1

PLIST_FILES=	bin/hashdeep bin/md5deep bin/sha1deep bin/sha256deep \
		bin/whirlpooldeep bin/tigerdeep

.include <bsd.port.mk>
