# ex:ts=8
# Ports collection makefile for:  cwish
# Date created:			  Thur Sept 25, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	cwish
PORTVERSION=	3.52
CATEGORIES=	misc
MASTER_SITES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based user friendly windowing shell

NO_WRKSUBDIR=	yes
ALL_TARGET=	cwish
MAN1=		cwish.1
PLIST_FILES=	bin/cwish

pre-configure:
	${CP} ${WRKSRC}/Makefile.FreeBSD ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cwish ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cwish.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
