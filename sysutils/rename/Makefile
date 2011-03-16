# New ports collection makefile for:	rename
# Date created:				7 July 2005
# Whom:					Chad Castleberry AKA ritalin
#
# $FreeBSD$
#

PORTNAME=	rename
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	Rename multiple files using regular expressions

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		rename.1

post-extract:
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
