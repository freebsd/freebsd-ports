# New ports collection makefile for:	rename
# Date created:				7 July 2005
# Whom:					Chad Castleberry AKA ritalin
#
# $FreeBSD$
#

PORTNAME=	rename
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://portfolio.iu.edu/crcastle/

MAINTAINER=	crcastle@ius.edu
COMMENT=	Rename multiple files using regular expressions

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		rename.1

post-extract:
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
