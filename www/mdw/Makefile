# New ports collection makefile for:	mdw
# Date created:				5 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mdw
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://www.redbrick.dcu.ie/~colmmacc/mdw/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A utility to check the MD5 sum of a webpage

USE_AUTOCONF_VER=	213
USE_REINPLACE=	yes

MAN1=	mdw.1

post-patch:
	@${REINPLACE_CMD} -e 's!quite!quiet!g; s!.BR md5sum (1),!!' \
		${WRKSRC}/doc/mdw.1

post-install:
	@${MKDIR} ${PREFIX}/share/examples/mdw
	${INSTALL_DATA} ${WRKSRC}/doc/example.sh ${PREFIX}/share/examples/mdw

.include <bsd.port.mk>
