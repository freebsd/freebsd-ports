# New ports collection makefile for:   xtail
# Date created:        20 January 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	xtail
PORTVERSION=	2.1
CATEGORIES=	misc
MASTER_SITES=	http://www.unicom.com/sw/xtail/ \
		http://www.giovannelli.it/~gmarco/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	Watches the growth of files or directories

HAS_CONFIGURE=	yes

MAN1=		xtail.1
PLIST_FILES=	bin/xtail

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtail ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xtail.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
