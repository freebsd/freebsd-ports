# $FreeBSD$

PORTNAME=	entr
PORTVERSION=	2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Runs arbitrary commands when files change

WRKSRC=	${WRKDIR}/eradman-entr-963b395019be

MAKEFILE=	Makefile.bsd
MAKE_ARGS=	MANPREFIX=${MANPREFIX}/man
PLIST_FILES=	bin/entr
MAN1=	entr.1
MANCOMPRESSED=	no

NO_STAGE=	yes
.include <bsd.port.mk>
