# New ports collection makefile for:	md5deep
# Date created:		15 July 2004
# Whom:			Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	md5deep
PORTVERSION=	1.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	Program to compute MD5 and SHA1 message digests recursively

ALL_TARGET=	unix
USE_REINPLACE=	yes

MAN1=		md5deep.1
MLINKS=		md5deep.1 sha1deep.1 md5deep.1 sha256deep.1 md5deep.1 whirlpooldeep.1

PLIST_FILES=	bin/md5deep bin/sha1deep bin/sha256deep bin/whirlpooldeep

post-patch:
	@${REINPLACE_CMD} -e 's!/usr/local!${PREFIX}!g' \
		-e 's!-Wall -O2!$(CFLAGS)!' \
		-e 's!gcc!$(CC)!' \
		-e 's!$$(CC)!$$(_CC)!' \
		-e 's!^CC!_CC!' ${WRKSRC}/Makefile

.include <bsd.port.mk>
