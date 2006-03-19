# New ports collection makefile for:	empty
# Date created:		17 September 2005
# Whom:			Mikhail Zakharov <zmey20000@yahoo.com>
#
# $FreeBSD$

PORTNAME=	empty
PORTVERSION=	0.6.9b
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	zmey20000@yahoo.com
COMMENT=	Expect-like tool for pure shell

MAN1=		empty.1

PLIST_FILES=	bin/empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/empty ${PREFIX}/bin/empty
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
