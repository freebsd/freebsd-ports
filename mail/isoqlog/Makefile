# New ports collection makefile for:   isoqlog
# Date created:                 17 June 2002
# Whom:                         Omer Faruk Sen <roots@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	isoqlog
PORTVERSION=	2.0
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/isoqlog/ \
		http://www.trunix.org/isogloq/    \
		http://www.acikkod.org/softwares/

MAINTAINER=	roots@enderunix.org

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.mk>
