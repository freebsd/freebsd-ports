# New ports collection makefile for:	htpdate
# Date created:			9 Jun 2005
# Whom:				Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	htpdate
PORTVERSION=	0.8.1
CATEGORIES=	net
MASTER_SITES=	http://www.clevervest.com/htp/archive/c/

MAINTAINER=	vsevolod@highsecure.ru
COMMENT=	Time synchronization over http utility

USE_BZIP2=	yes

MAN8=	htpdate.8

PLIST_FILES=	bin/htpdate

post-extract:
	@${GZIP_CMD} -d ${WRKSRC}/${MAN8}.gz

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/htpdate ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
